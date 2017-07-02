//
//  ChangeCartoonViewController.swift
//  RxDelegateReplacement
//
//  Created by raj on 02/07/17.
//  Copyright © 2017 diskodev. All rights reserved.
//

import UIKit
import RxSwift

class ChangeCartoonViewController: UIViewController, UITextFieldDelegate {
    var cartoonTextField: UITextField!
    var changeButton: UIButton!

    var cartoonPublishSubject = PublishSubject<String>()
    var cartoonObserver: Observable<String> {
        return cartoonPublishSubject.asObservable()
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        setupView()

        setupCartoonTextField()
        setupChangeButton()
    }

    func setupView() {
        self.view.backgroundColor = .white
    }

    func setupCartoonTextField() {
        cartoonTextField = UITextField()
        cartoonTextField.translatesAutoresizingMaskIntoConstraints = false

        cartoonTextField.borderStyle = .line
        cartoonTextField.delegate = self

        self.view.addSubview(cartoonTextField)

        self.view.addConstraint(cartoonTextField.widthAnchor.constraint(equalTo: (cartoonTextField.superview?.widthAnchor)!, multiplier: 0.80))
        self.view.addConstraint(cartoonTextField.heightAnchor.constraint(equalToConstant: 40.0))
        self.view.addConstraint(cartoonTextField.centerXAnchor.constraint(equalTo: (cartoonTextField.superview?.centerXAnchor)!))
        self.view.addConstraint(cartoonTextField.centerYAnchor.constraint(equalTo: (cartoonTextField.superview?.centerYAnchor)!))
    }

    func setupChangeButton() {
        changeButton = UIButton()
        changeButton.translatesAutoresizingMaskIntoConstraints = false

        changeButton.setTitle("Change", for: .normal)
        changeButton.setTitleColor(.blue, for: .normal)
        changeButton.sizeToFit()

        self.view.addSubview(changeButton)

        changeButton.addTarget(self, action: #selector(ChangeCartoonViewController.changeButtonPressed(_:)), for: .touchUpInside)

        self.view.addConstraint(changeButton.topAnchor.constraint(equalTo: cartoonTextField.bottomAnchor, constant: 15.0))
        self.view.addConstraint(changeButton.centerXAnchor.constraint(equalTo: (changeButton.superview?.centerXAnchor)!))
    }

    func changeButtonPressed(_ button: UIButton) {
        cartoonPublishSubject.onNext(cartoonTextField.text!)
        cartoonPublishSubject.onCompleted()

        self.dismiss(animated: true)
    }

    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        textField.resignFirstResponder()
        return true
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
