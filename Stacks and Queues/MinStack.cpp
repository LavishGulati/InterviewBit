stack<int> output;
stack<int> s;


MinStack::MinStack() {
    while(!output.empty()) output.pop();
    while(!s.empty()) s.pop();
}

void MinStack::push(int x) {
    s.push(x);
    if(output.size() > 0 && x <= output.top()) output.push(x);
    else if(output.size() == 0) output.push(x);
}

void MinStack::pop() {
    if(s.empty()) return;
    if(output.size() > 0 && s.top() == output.top()) output.pop();
    s.pop();
}

int MinStack::top() {
    if(s.empty()) return -1;
    return s.top();
}

int MinStack::getMin() {
    if(output.empty()) return -1;
    return output.top();
}
