// dynamic_cast<> : 런타임 시 상향 혹은 하향 형변환 한다.	
// 동적으로 생성된 객체를 가리키는 포인터가 기본 형식인 경우라면 구체적으로 어떤 객체에 대한 인스턴스인지 확인할 필요가 있을 것이다.
// 이때 사용하기 좋은 연산자이다. 단, 꼭 필요한 경우가 아니라면 절대로 사용하지 말아야 한다.
// 성능을 떨어뜨리는 주범이며, 코드를 복잡하게 잡아 늘리기때문이다.
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
	cout << "도형 번호를 입력하세요. [1:사각형, 2:원]: " << endl;
	int nInput = 0;
	cin >> nInput;

	CShape* pShape = nullptr;
	if (nInput == 1)
		pShape = new CRectangle();
	else if (nInput == 2)
		pShape = new CCircle();
	else
		pShape = new CShape;

	// 좋은 예
	pShape->Draw();

	// '매우' 나쁜 예
	// 가상 함수를 활용한다면 이런 코드를 작성할 이유가 없다.
	CRectangle* pRect = dynamic_cast<CRectangle*>(pShape);
	
	// dynamic_cast 연산자는 형변환에 실패하면 NULL 을 반환한다.
	// 이를 조사하는 방법으로 바른 변환인지 아닌지를 확인할 수 있는데 이와 같은 방법을 RTTI(Run-Time Type Information(or Identification) 라 한다.
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