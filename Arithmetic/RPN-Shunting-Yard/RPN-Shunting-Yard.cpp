#include <iostream>
#include <stack>

int GetPriority(char c) {
  switch (c) {
    case '(': return 0;
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;
    case '%': return 2;
    case '^': return 3;
    default: return -1;
  }
}

void RPN(char c) {
  std::stack<char> out;
  std::stack<char> operators;

  do {
    if (c == ';') break;
    else if (c == ' ') continue;
    else if (c == ')') {
      while (operators.top() != '(') {
        //out.push(' ');
        out.push(operators.top());
        operators.pop();
      }
      operators.pop();
    }
    else {
      int priority = GetPriority(c);
      if (priority < 0) {
        out.push(c);
      }
      else if (priority == 0) {
        operators.push(c);
      }
      else {
        while (!operators.empty() && (GetPriority(operators.top()) >= priority)) {
          //out.push(' ');
          out.push(operators.top());
          operators.pop();
        }
        //out.push(' ');
        operators.push(c);
      }
    }
  } while (std::cin >> c);

  while (!operators.empty()) {
    //out.push(' ');
    out.push(operators.top());
    operators.pop();
  }

  std::string s;
  while (!out.empty()) {
    s += out.top();
    out.pop();
  }
  std::reverse(s.begin(), s.end());
  std::cout << s << '\n';
}

int main()
{
  char c;

  while (std::cin >> c) {
    RPN(c);
  }
}