class MyStack {
private:
  queue<int> q;

public:
  MyStack() {}
  
  void push(int x) {
    q.push(x);
    for (int i = 0; i < q.size() - 1; i++) {
      q.push(q.front());
      q.pop();
    }
  }
  
  int pop() {
    const int fnt = q.front();
    q.pop();
    return fnt;
  }
  
  int top() {
    return q.front();
  }
  
  bool empty() {
    return q.empty();
  }
};