#pragma once
#include <string>
#include <iostream>

using namespace std;


class CPU
{
public:
	CPU(string);
	virtual void start() = 0;
	virtual void close() = 0;
protected:
	string model;
};

class DisplayCard
{
public:
	DisplayCard(string);
	virtual void start() = 0;
	virtual void close() = 0;
protected:
	string model;
};

class Memory
{
public:
	Memory(string);
	virtual void start() = 0;
	virtual void close() = 0;
protected:
	string model;	
};

class MainBoard
{
public:
	~MainBoard();

	void operation();
	void closeComputer();

	MainBoard(CPU *, Memory *, DisplayCard *);

private:
	CPU *cpu;
	DisplayCard *card;
	Memory *memory;
};
