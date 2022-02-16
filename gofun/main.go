package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/smtp"
	"os"
)

func main() {
	//I'll use my real account
	toUser := "test"
	from := "misterphoenix6@gmail.com"
	password := "mister_66"

	toList := []string{toUser}
	host := "smtp.gmail.com"
	port := "587"

	pagefile, err := os.Open("page.html")
	if err != nil {
		log.Fatal(err)
	}
	defer func() {
		if err = pagefile.Close(); err != nil {
			log.Fatal(err)
		}
	}()
	content, err := ioutil.ReadAll(pagefile)

	subject := "Subject: Test email from Go!\n"
	mime := "MIME-version: 1.0;\nContent-Type: text/html; charset=\"UTF-8\";\n\n"
	body := fmt.Sprintf(string(content))
	msg := []byte(subject + mime + body)

	auth := smtp.PlainAuth("", from, password, host)
	error := smtp.SendMail(host+":"+port, auth, from, toList, msg,)
	if error != nil {
		fmt.Println(error)
		os.Exit(1)
	}
	fmt.Println("Success")
}
