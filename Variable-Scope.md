# Variable, Variable Scope

------------------------  
**Contents about Variable Scope + Variable elements**
- 변수의 유효범위를 알기 위해서는 다음과 같은 사전 지식들이 필요하다.
  - 변수의 지시자(specifier)의 역할.
  - 블록의 개념.
  - 메모리의 구성
    - 낮은 주소 --> 높은 주소 순
    - Code - Data - BSS(Block Started by Symbol) - Heap - Stack
    - 위의 순서를 이미지로 보면 다음과 같다.
    - ![Stack Frame](http://cfile6.uf.tistory.com/image/132FAD1B4B71686527387D)
      1. 코드에는 프로그램의 소스코드 데이터가 들어간다.
      2. 데이터 영역은 static memory라고 하고, **전역변수, local static 변수 이면서 선언이 아닌, 상수가 할당된 변수**
      가 온다.
      3. BSS 영역은 할당이 되지 않고, **선언** 만 된 **전역변수, local static변수** 들이 온다.
      4. 힙 영역. 런타임시에 동적으로 할당되는 메모리이다.
      다른 말로, 할당해야 할 메모리의 크기를 프로그램이 실행되는 동안 결정해야 하는 경우(런 타임때) 유용하게 사용되는 공간이다.
      5. Stack 영역. 함수 호출시 지역변수와 매개변수가 저장되는 공간이다. 함수의 호출이 끝나고 난 후, 스택 포인터는
      이전 함수의 위치로 이동하여 호출 시점 이전으로 돌아간다. 함수 호출이 끝나고 난 이후, 스택에 쌓였었던 메모리 공간은
      쓰레기(garbage)값을 가지게 되는데, C는 이를 청소하지 않는다. 그래서 변수를 선언만 하고 쓸 경우, 운 나쁠 경우 이 쓰레기 값이 들어갈 수도 있다. 현대 언어들은 Garbage Collector를 이용해서 변수가 더 이상 참조되지 않을 경우, 값을 수거해서 파기시킨다.
  - 컴파일러가 컴파일을 하며 하는 일, 런타임에 수행되는 일.
- 변수가 **유효범위** 를 가지기 때문에 가지는 여러가지 이점이 있는데 이러한 성질을 적어보자면 다음과 같다.
  - modulability : 함수의 독립적 설계가 가능.
  - reusability : 단위 기능을 수행하는 모듈을 함수로 만들어 놓으면, 다른 프로그램에서 사용 가능하다.
  - portability : 하드웨어 독립적 기능을 함수로 만들면, CPU가 바뀌어도 사용 가능하다.
  - **결론 : 함수를 잘 설계하자.** 이는 UNIX 설계 철학에도 맞닿아 있다.
- **함수는 지역 함수를 만들 수 없다.**
  - 하지만, 함수 내부에 함수 선언은 가능하다.
- **Visibility** 변수를 사용하기 전에, 항상 그 이전에 선언(혹은 값이 할당)되어 있어야 한다.


## Storage Class
- 변수가 저장되는 메모리 공간의 개념.
- 서비스가 다른 3계급(class)의 저장공간이 있다. 종류는 다음과 같다.
  - static memory : 프로그램 전체에서 사용되는 고정적 변수. Data영역에 선언된다. (낮은 주소 -> 높은 주소)
  초기화 안해도 0으로 자동 초기화 됨. **프로그램** 과 라이프 싸이클이 일치한다.
  - stack : 개별 함수에 독자적으로 사용되는 임시 변수들, 함수, 등이 들어간다. (높은 주소 -> 낮은 주소)
  보통 **함수** 혹은 **블록{}** 과 라이프 싸이클이 일치한다.
  - register : CPU내부의 레지스터에 저장. 사용을 한다면, **반드시 초기화 해야 한다.** 초기화를 하지 않으면 쓰레기 값이 들어간다. 거의 사용 안함.

## Elements of variable.
- 변수는 다음과 같은 요소에 의해 선언된다.
- **specifier** + **modifier** + **identifier** **;**

### Specifier(지정자)
- Type specifier
  - 변수의 타입을 지정해준다.(char, short, int, long, long long, doubel, float, struct, union, enum)
  - 변수를 만들때 반드시 있어야 하며, **형 지정자** 는 변수의 크기와 성격을 나타낸다.
  - 추후에 다루겠지만, type specifier앞에 type qualifier를 붙여서 변수의 행동을 결정할 수 있다.(const, volatile)

- Storage class specifier
  - 변수가 지정되는 공간의 등급을 지정한다. 다음과 같은 것들이 있다.
  - extern : static memory에 저장되지만, 지정자가 블록내부에서 선언되어 있는지, 아닌지에 따라 유효범위가 다르다.
  다른 파일내에 지정되어 있는 전역변수를 쓸 수 있도록 도와주는 지정자이다. 블록내에 선언될 시에는 전역변수의 변수값을 참조하지만, 블록내에서만 유효하다.
  - static : static memory에 저장되지만, 지정자가 블록내부에서 선언되어 있는지, 아닌지에 따라 유효범위가 다르다.
  전역 변수로 선언될 경우, 해당 파일에서만 변수 범위가 유효하다. 함수 내부의 블록에서 선언될 경우, 유효범위가 블록만큼만 적용된다.
  하지만, 변수는 static memory영역에 저장된다.
  - auto : 선언 위치에 따라 다름. 컴파일러가 알아서 stack 또는 register로 공간을 잡아준다.
  - register :
  - default :

### Modifier(수정자)
- 수정자는 변수의 타입을 변경(modifiy) 시켜준다.
  - **\*** : 포인터. 변수를 주소타입으로 바꿔준다.
  - **[]** : 배열(array)이라고 읽는다. 변수를 한 개가 아닌 집합으로 바꿔준다.
  - **()** : 함수(function)라고 읽으며, 변수를 함수로 바꿔줌.
  - 예를 들어보면 다음과 같다.
    - ``` int a;``` : 기본형 int타입 a.
    - ``` int *a;``` : 주소 타입의 포인터가 됨.
    - ``` int a[10];``` : a가 int 한 개가 아니라 10개 짤 집합(배열)이 된다.
    - ``` int a(int); ``` : a가 int가 아니라 함수가 된다.

### Identifier(식별자)
- 프로그램에서 **변수, 형식, 함수, 레이블** 에 제공하는 이름. 쉽게 말해서, 변수의 이름,
함수의 이름, 레이블등에 쓰이는 것.
  - C에서 함수의 식별자가 같으면, 반환 타입, 인자가 달라도 같은 함수로 취급한다. 즉 중복 선언이 불가하다.
- identifier는 alphanumeric character와 underscore(\_)로만 구성된다.
- identifier의 첫 글자는 반드시 alphabet만 와야 한다.
- identifier는 예약어(reserved words)들은 피해야 한다.
  - 다음은 예약어의 종류들이다.

```cpp

  auto	double	int	struct
  break	else	long	switch
  case	enum	register	typedef
  const	extern	return	union
  char	float	short	unsigned
  continue	for	signed	volatile
  default	goto	sizeof	void
  do	if	static	while

```

- 실제 코드에서 예약어들을 찾아보자.

```cpp

#include <stdio.h>
int main(){
  int qty = 45;
  float price = 12.75;
  char item_Code = 'A';
  char C_name[20] = "Naomi";
  printf("%s take %d %c item which price is $%0.2f per item\n",C_name,qty,item_Code,price);
  return 0;
}

```
- 위 코드에서 identifier들을 적어보면 다음과 같다.
  - qty
  - price
  - item_Code
  - C_name


## Stack
- c에서 메모리를 취급하는 방법을 제대로 이해하기 위해서는 스택에 대한 이해가 필요하다.
- 스택은 지역변수를 저장하고, argument를 전달하는 목적으로 사용한다.
- 스택을 메모리에 align 시킬때는 다음 조건을 충족해야 한다.
  - 8B 데이터(double, long long 등)는 4의 배수의 주소에 넣어야 한다.
  - int는 4의 배수 주소에 넣어야 한다.
  - short는 짝수 주소에 넣어야 한다.
  - char는 임의의 주소에 들어간다.
  - 이러한 규칙을 지킬 경우, char형의 메모리 전에는 padding
- 함수 호출시에 인자를 넘기는 경우, 스택 영역에 call stack frame이 쌓이고, 높은 주소부터 함수 인자의 뒷 부분부터
값이 쌓이기 시작한다.
- 함수가 호출되면 새로운 스택이 생성되고, 이전의 스택은 모두 비활성화(invisible) 된다.
- 스택에서 가장 상단의 스택을 활성(active stack) 스택이라고 하며, 이 스택안에 선언된 변수만 액세스 가능하다.(static memory영역 제외), 물론 포인터를 이용해서 비활성 스택의 값들에 접근하여 조작할 수 있다.
- 컴파일러는 변수를 찾을 때
  1. active stack부터 찾는다.
  2. 없으면 static memory를 찾는다.


## Global Variable
- **컴파일 시점** 에 값이 저장된다.
- 전역변수를 가장 양질의 서비스를 제공받는다.
- 이 말은 변수를 선언만 해도 자동으로 값이 할당된다는 뜻이다.(0으로 할당됨.)
- 전역변수의 선언은 **상수** 혹은 **상수식** 만 가능하다. 표현해보면 다음과 같다.
  - 전역변수의 = 연산자 우측에는 변수가 오지 못한다.
- 전역변수는 낮은 주소의 메모리부터 채워진다. 물론, 전역변수는 컴파일 시점에 주소가 정해진다.

```cpp
#include <stdio.h>

int a;             // 선언식 가능 (0으로 초기화 됨.)
int b = 3;         // 상수식 가능
int c = b;         // 변수식이라 불가.
int d = c = 10     // 변수식 불가.
int e = sizeof(a); // a가 변수라서 불가능할 것 같지만, sizeof연산자는 컴파일 시점에 a의 형을 기반으로
                   // 크기를 추론한다.  
                   // 모든 연산자 중에 오직 sizeof연산자 만이 컴파일 타임에 값을 평가한다.
a = 30;            // 문법을 엄격하게 지키는 컴파일러는 error. 최근 컴파일러는 알아서 int를 붙여줌.
int o, char p;     // 타입을 분류해서 선언해야 한다.

void main(void)
{
  int local = 20;
  local = 30;
  printf("d\n", local);
  int local2 = local;  // 코드 중간에 변수 선언 불가. (과거버전)
}
```

## Local Variable
- 실행시에 값이 생성되고 저장된다.
- Block ( { } )단위로 유효하다.
- 블록에 선언된 static 메모리는 블록 내부에서만 유효하나, 값 자체는 static memory영역에 저장된다.
**또한, 이 값은 컴파일시점에 이미 저장영역과 값이 정해진다.**


------------------------  
함수가 호출되면서 내부적으로 스택에 값이 쌓이는데, 이러한 성질을 이용해서 재귀함수를 사용할 수 있다.

```cpp
// 한 정수 N을 입력 받아서 N층의 이등변 삼각형 모양의 별을 출력하시오.
// 단, 반드시 재귀함수로 구현하시오.
// input 3

// output
// *
// **
// ***
// **
// *

// stack
// |   3   |  draw(3)   | print_star(3) ***  ↑    |
// |   2   |  draw(2)   | print_star(2) **   ↑    |  print_star(2) **  ↓
// |   1   |  draw(1)   | print_star(1) *    ↑    |  print_star(1) *   ↓
// |-------| call stack |

// 전역변수를 사용하면 다음과 같이 사용할 수 있다.
#include <stdio.h>
int peak;

void draw(int);
void print_star(int);

void main(void)
{
	scanf("%d", &peak);
	draw(1);
}

void draw(int cnt)
{
	print_star(cnt); // stack frame이 생성되면서 stack에 쌓인 변수 cnt를 사용.
	if (cnt == peak) return;  // 전환점.
	draw(cnt + 1);
	print_star(cnt); // call stack이 사라지면서 stack frame에 남아있던 변수 cnt를 활용.
}

void print_star(int iter_cnt)
{
	for (int i = 0; i < iter_cnt; i++) {
		printf("*");
	}
	printf("\n");
}

```


------------------------  
**Contents about Variable(especially collection of data, eg. array, struct)**
## Homogeneous
- array

## Heterogeneous
[자세한 문서는 이곳](https://github.com/csyouk/deepdive_into_c/blob/master/Struct-Union.md)
- struct
- union
