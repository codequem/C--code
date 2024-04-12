//这是递归类型的解法
void hanoi(int n, char from, char to, char via) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
    } else {
        hanoi(n - 1, from, via, to);
        cout << "Move disk " << n << " from " << from << " to " << to << endl;
        hanoi(n - 1, via, to, from);
    }
}

//如何不递归的去解决这个问题呢？
//我们来模拟c++调用我们函数的过程

