#include <iostream>
#include <string>

using namespace std;

const string name = "E22214111 程一帆";

class Item
{
private:
    string name;
    double value;
    int count;
    Item *it;

public:
    Item(string name = "unknown", double value = 0, int count = 0, Item *it = nullptr) : name(name), value(value), count(count), it(it) {}
    Item(const Item &i) : name(i.name), value(i.value), count(i.count), it(i.it) {}

    string getname() { return name; }
    double getvalue() { return value; }
    int getcount() { return count; }
    Item *getNextItem() { return it; }

    void setname(string name) { this->name = name; }
    void setvalue(double value) { this->value = value; }
    void setcount(int count) { this->count = count; }
    void setNextItem(Item *it) { this->it = it; }
};

class Cart
{
private:
    Item *header;

public:
    Cart() { header = nullptr; }
    ~Cart()
    {
        Item *it = this->header;
        while (it != nullptr)
        {
            Item *temp = it->getNextItem();
            delete it;
            it = temp;
        }
    }
    Cart(const Cart &c)
    {
        header = c.header;
        Item *temp = c.header;
        while (temp != nullptr)
        {
            addItem(*temp);
            temp = temp->getNextItem();
        }
    }
    void addItem(Item &i)
    {
        deleteItem(i.getname());
        if (header == nullptr)
        {
            header = new Item(i);
        }
        else
        {
            Item *end = header;
            while (end->getNextItem() != nullptr)
                end = end->getNextItem();
            Item *temp = new Item(i);
            end->setNextItem(temp);
        }
        return;
    };
    bool deleteItem(string name)
    {
        bool flag = false;
        Item *temp = header;
        Item *prev = temp;
        while (temp != nullptr)
        {
            if (temp->getname() == name)
            {
                flag = true;
                prev->setNextItem(temp->getNextItem());
                if (temp == header)
                    header = header->getNextItem();
                delete temp;
                break;
            }
            else
            {
                prev = temp;
                temp = temp->getNextItem();
            }
        }
        return flag;
    };
    void showInfo()
    {
        if (header == nullptr)
            return;

        Item *temp = header;
        int id = 1;
        while (temp != nullptr)
        {
            cout << "Item" << id++
                 << " name:" << temp->getname()
                 << " value:" << temp->getvalue()
                 << " count:" << temp->getcount()
                 << " total:" << temp->getcount() * temp->getvalue() << endl;
            temp = temp->getNextItem();
        }
        cout << "Cart Total:" << getsum() << endl;
    };
    double getsum()
    {
        double ans = 0;
        Item *temp = header;
        while (temp != nullptr)
        {
            ans += temp->getcount() * temp->getvalue();
            temp = temp->getNextItem();
        }
        return ans;
    };
};

int main(void)
{
    cout << name << endl;

    Cart c;
    char op = 'r';
    while (op != 'c')
    {
        int flag = 0;
        cout << "请选择您要进行的操作:1.添加货物,2.删除货物,3.显示货物清单,4.获取货物总价,5.结束操作:  " << endl;
        cin >> flag;
        switch (flag)
        {
        case 1:
        {
            string name;
            double value;
            int count;
            cout << "请输入货物的名称，单价，数目:   " << endl;
            cin >> name >> value >> count;
            Item i(name, value, count);
            c.addItem(i);
            break;
        }
        case 2:
        {
            string name;
            cout << "请输入您要删除的货物的名称:   ";
            cin >> name;
            c.deleteItem(name);
            break;
        }
        case 3:
        {
            c.showInfo();
            break;
        }
        case 4:
        {
            cout << "Cart Total:" << c.getsum() << endl;
            break;
        }
        case 5:
        {
            op = 'c';
            break;
        }
        }
    }
    return 0;
}