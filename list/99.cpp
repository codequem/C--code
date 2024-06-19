#include <iostream>
#include <string>

using namespace std;

const string name = "E22214111 程一帆";

class Publication {
    private:
        string title;
        string author_name;
        string author_organization;
        int pages;
        string publication_date;
    public:
        Publication() = default;
        Publication(string title, string author_name, string author_organization, int pages, string publication_date) {
            this->title = title;
            this->author_name = author_name;
            this->author_organization = author_organization;
            this->pages = pages;
            this->publication_date = publication_date;
        }
        Publication(const Publication &p) {
            this->title = p.title;
            this->author_name = p.author_name;
            this->author_organization = p.author_organization;
            this->pages = p.pages;
            this->publication_date = p.publication_date;
        }
        virtual ~Publication() {}
        virtual void show(){
            cout << "============文档信息:============"<<endl;
            cout << "标题 = " << title << ";";
            cout << "作者 = " << author_name << ";";
            cout << "单位 = " << author_organization << ";";
            cout << "页数 = " << pages << ";";
            cout << "出版日期 = " << publication_date << endl;
        }
};

class Thesis: public Publication {
    public:
        enum ThesisType
        {
            BACHELOR,
            MASTER,
            DOCTOR
        };
    private:
        string advisor_name;
        ThesisType academic_degree;
    public:        
        Thesis() = default;
        Thesis(string title, string author_name, string author_organization, int pages, string publication_date, string advisor_name, ThesisType academic_degree): Publication(title, author_name, author_organization, pages, publication_date){
            this->advisor_name = advisor_name;
            this->academic_degree = academic_degree;
        }
        Thesis(const Thesis &t): Publication(t){
            this->advisor_name = t.advisor_name;
            this->academic_degree = t.academic_degree;
        }
        virtual ~Thesis() {}
        virtual void show(){
            Publication::show();
            cout << "这是一篇";
            switch (academic_degree)
            {
            case BACHELOR:
                cout << "学士";
                break;
            case MASTER:
                cout << "硕士";
                break;
            case DOCTOR:
                cout << "博士";
                break;
            default:
                break;
            }
            cout << "学位论文;";
            cout << "指导教师 = " << advisor_name << ";";
            cout << endl;
        }
};

class Article: public Publication {
    private:
        string journal_name;
    public:
        Article() = default;
        Article(string title, string author_name, string author_organization, int pages, string publication_date, string journal_name): Publication(title, author_name, author_organization, pages, publication_date){
            this->journal_name = journal_name;
        }
        Article(const Article &a): Publication(a){
            this->journal_name = a.journal_name;
        }
        virtual ~Article() {}
        virtual void show(){
            Publication::show();
            cout << "这是一篇期刊论文,发表期刊 = " << journal_name << ";";
        }
};

int main (void)
{
    cout << name << endl;
    Publication p1("C++ 语言程序设计","郑莉、董渊","清华大学", 540,"2020");
    Thesis t1("城市社区老年人数字融入影响机制","王辉","清华大学", 175,"2021","金兼斌",Thesis::DOCTOR);
    Thesis t2("物联网任务自动部署的研究与实现","李宗浩","北京航空航天大学", 95,"2014","夏春和",Thesis::MASTER);
    Article a1("嵌入式智能计算机计算能力评测方法","马春燕","西北工业大学", 23,"2023","计算机学报");

    p1.show();
    t1.show();
    t2.show();
    a1.show();

    return 0;
}