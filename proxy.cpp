// proxy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
using namespace System;


ref class Image abstract {
public:
	virtual void display() = 0;
	~Image(){;}
};

ref class RealImage : Image {

private:
	String^ fileName;
	void loadFromDisk(String^ fileName){
		Console::Write("Loading ");
		Console::Write(fileName);
		Console::WriteLine();
	}
public:
	RealImage(String^ fileName){
		this->fileName = fileName;
		loadFromDisk(fileName);
	}

	virtual void display() override {
		Console::Write("Displaying ");
		Console::Write(fileName);
		Console::WriteLine();
	}
};

ref class ProxyImage : Image{

private: 
	RealImage^ realImage;
	String^ fileName;

public:
	ProxyImage(String^ fileName){
		this->fileName = fileName;
	}


	virtual void display() override {
		if(!realImage){
			realImage = gcnew RealImage(fileName);
		}
		realImage->display();
	}
};



int _tmain(int argc, _TCHAR* argv[])
{

	Image^ image = gcnew ProxyImage("test_10mb.jpg");
	image->display(); 
	Console::WriteLine("");
	image->display(); 
	Console::ReadLine();
	return 0;
}

