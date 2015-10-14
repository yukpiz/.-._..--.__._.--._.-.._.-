package main

import (
	"log"
	"syscall"
	"unsafe"
)

func main() {
	dll, err := syscall.LoadDLL("user32.dll")
	if err != nil {
		log.Fatal(err)
	}
	defer dll.Release()

	proc, err := dll.FindProc("MessageBoxW")
	if err != nil {
		log.Fatal(err)
	}

	proc.Call(0,
		uintptr(unsafe.Pointer(syscall.StringToUTF16Ptr("メッセージ"))),
		uintptr(unsafe.Pointer(syscall.StringToUTF16Ptr("ボックス"))),
		0)
}
