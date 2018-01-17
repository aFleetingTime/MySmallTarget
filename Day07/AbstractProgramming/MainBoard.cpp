#include "MainBoard.h"



MainBoard::MainBoard(CPU *cpu, Memory *memory, DisplayCard *card = nullptr)
{
	this->cpu = cpu;
	this->memory = memory;
	this->card = card;
}

MainBoard::~MainBoard()
{
	if (cpu != nullptr)
		delete cpu;
	if (card != nullptr)
		delete card;
	if (memory != nullptr)
		delete memory;
}

void MainBoard::operation()
{
	if(cpu == nullptr)
		cout << "û�а�װCPU��������޷�����" << endl;
	if(memory == nullptr)
		cout << "û�в����ڴ�����������޷�����" << endl;

	this->cpu->start();
	this->memory->start();

	if (card != nullptr)
		this->card->start();
}

void MainBoard::closeComputer()
{
	if (cpu != nullptr)
		this->cpu->close();
	if (memory != nullptr)
		this->memory->close();
	if (card != nullptr)
		this->card->close();

	cout << "������ѹر�..." << endl;
}

DisplayCard::DisplayCard(string model)
{
	this->model = model;
}

CPU::CPU(string model)
{
	this->model = model;
}

Memory::Memory(string model)
{
	this->model = model;
}
