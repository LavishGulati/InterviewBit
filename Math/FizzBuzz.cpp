#define pb push_back

vector<string> Solution::fizzBuzz(int A) {
    vector<string> output;
    for(int i = 1; i <= A; i++){
        if(i%15 == 0) output.pb("FizzBuzz");
        else if(i%3 == 0) output.pb("Fizz");
        else if(i%5 == 0) output.pb("Buzz");
        else output.pb(to_string(i));
    }
    return output;
}

