//
//  CartoonViewController.swift
//  RxDelegateReplacement
//
//  Created by raj on 02/07/17.
//  Copyright © 2017 diskodev. All rights reserved.
//

import UIKit
import RxSwift

class CartoonViewController: UIViewController {
    var nameLabel: UILabel!
    var changeButton: UIButton!

    let disposeBag = DisposeBag()
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        setupView()

        setupNameLabel()
        setupChangeButton()
    }
    
    func setupView() {
        self.view.backgroundColor = .white
    }

    func setupNameLabel() {
        nameLabel = UILabel()
        nameLabel.translatesAutoresizingMaskIntoConstraints = false

        nameLabel.text = "SWAT Kats"
        nameLabel.font = UIFont(descriptor: .preferredFontDescriptor(withTextStyle: .headline), size: 29.0)
        nameLabel.sizeToFit()
        
        self.view.addSubview(nameLabel)

        self.view.addConstraint(nameLabel.centerXAnchor.constraint(equalTo: (nameLabel.superview?.centerXAnchor)!))
        self.view.addConstraint(nameLabel.centerYAnchor.constraint(equalTo: (nameLabel.superview?.centerYAnchor)!))
    }

    func setupChangeButton() {
        changeButton = UIButton()
        changeButton.translatesAutoresizingMaskIntoConstraints = false

        changeButton.setTitle("Change Cartoon", for: .normal)
        changeButton.setTitleColor(.blue, for: .normal)
        changeButton.sizeToFit()

        changeButton.addTarget(self, action: #selector(CartoonViewController.changeButtonPressed(_:)), for: .touchUpInside)

        self.view.addSubview(changeButton)

        self.view.addConstraint(changeButton.topAnchor.constraint(equalTo: nameLabel.bottomAnchor, constant: 15.0))
        self.view.addConstraint(changeButton.centerXAnchor.constraint(equalTo: (changeButton.superview?.centerXAnchor)!))
    }

    func changeButtonPressed(_ button: UIButton) {
        self.view.endEditing(true)

        let changeCartoonViewController = ChangeCartoonViewController()

        changeCartoonViewController.cartoonObserver
            .subscribe(onNext: { [weak self] cartoon in
                self?.nameLabel.text = cartoon
            }, onCompleted: {
                print("Completed.")
            }, onDisposed: {
                print("Disposed.")
            })
            .addDisposableTo(disposeBag)

        self.present(changeCartoonViewController, animated: true)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
