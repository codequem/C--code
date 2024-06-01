#include <iostream>
#include <string>

using namespace std;

const string myname = "E22214111 程一帆";

class student
{
private:
    static const double alpha ;
    static int now_id;
    string name;
    long uid;
    double score_1;
    double score_2;

public:
    student(string name)
    {
        this->name = name;
        uid = now_id++;
        score_1 = 0;
        score_2 = 0;
    }

    string getname()
    {
        return name;
    }

    long getuid()
    {
        return uid;
    }

    double getscore()
    {
        return score_1 * alpha + score_2 * (1 - alpha);
    }

    void setscore_1(double s)
    {
        score_1 = s;
    }

    void setscore_2(double s)
    {
        score_2 = s;
    }

    void ShowInfo()
    {
        cout << "Name:" << name << ','
             << "ID = " << uid << ','
             << "written score = " << score_1 << ','
             << "program score = " << score_2 << ','
             << "total score = " << getscore() << endl;
    }
};

const double student::alpha = 0.6;
int student::now_id = 1;

int main(void)
{
    cout<<myname<<endl;
    student G("guan");
    student C("cheng");
    student Y("yang");
    
    G.setscore_1(78);
    G.setscore_2(92);

    C.setscore_1(70);
    C.setscore_2(95);

    Y.setscore_1(93);
    Y.setscore_2(95);

    G.ShowInfo();
    C.ShowInfo();
    Y.ShowInfo();

    return 0;
}