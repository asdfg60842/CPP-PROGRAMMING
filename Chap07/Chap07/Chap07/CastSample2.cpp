// dynamic_cast<> : ��Ÿ�� �� ���� Ȥ�� ���� ����ȯ �Ѵ�.	
// �������� ������ ��ü�� ����Ű�� �����Ͱ� �⺻ ������ ����� ��ü������ � ��ü�� ���� �ν��Ͻ����� Ȯ���� �ʿ䰡 ���� ���̴�.
// �̶� ����ϱ� ���� �������̴�. ��, �� �ʿ��� ��찡 �ƴ϶�� ����� ������� ���ƾ� �Ѵ�.
// ������ ����߸��� �ֹ��̸�, �ڵ带 �����ϰ� ��� �ø��⶧���̴�.
#include <iostream>
using namespace std;

class CShape
{
public:
	CShape() { }
	virtual  ~CShape() { }
	virtual void Draw()
	{
		cout << "CShape::Draw()" << endl;
	}
};

class CRectangle
	: public CShape
{
public:
	virtual void Draw()
	{
		cout << "CRectangle::Draw()" << endl;
	}
};

class CCircle
	: public CShape
{
public:
	virtual void Draw()
	{
		cout << "CCircle::Draw()" << endl;
	}
};

int main()
{
	cout << "���� ��ȣ�� �Է��ϼ���. [1:�簢��, 2:��]: " << endl;
	int nInput = 0;
	cin >> nInput;

	CShape* pShape = nullptr;
	if (nInput == 1)
		pShape = new CRectangle();
	else if (nInput == 2)
		pShape = new CCircle();
	else
		pShape = new CShape;

	// ���� ��
	pShape->Draw();

	// '�ſ�' ���� ��
	// ���� �Լ��� Ȱ���Ѵٸ� �̷� �ڵ带 �ۼ��� ������ ����.
	CRectangle* pRect = dynamic_cast<CRectangle*>(pShape);
	
	// dynamic_cast �����ڴ� ����ȯ�� �����ϸ� NULL �� ��ȯ�Ѵ�.
	// �̸� �����ϴ� ������� �ٸ� ��ȯ���� �ƴ����� Ȯ���� �� �ִµ� �̿� ���� ����� RTTI(Run-Time Type Information(or Identification) �� �Ѵ�.
	if (pRect != NULL)
		cout << "CRectangle::Draw()" << endl;
	else
	{
		CCircle* pCircle = dynamic_cast<CCircle*>(pShape);
		
		if (pCircle != NULL)
			cout << "CCircle::Draw()" << endl;
		else
			cout << "CShape::Draw()" << endl;
	}

	return 0;
}