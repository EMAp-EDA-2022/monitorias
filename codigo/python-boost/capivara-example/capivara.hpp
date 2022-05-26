#include<vector>
#include<string>

using std::vector;
using std::string;

struct Column{
    int size;
    string name;

    Column(int, string);
};

class CapiFrame{
    vector<Column*> columns;
 public:
    int max_columns;
    
    CapiFrame(int);

    void NewColumn(int, string);
    
    int GetNumberColumns();
};

Column::Column(int size, string name) {
    this->size = size;
    this->name = name;
}

CapiFrame::CapiFrame(int max_columns){
    this->max_columns = max_columns;
}

void CapiFrame::NewColumn(int size, string name) {
    columns.push_back(new Column(size, name));
}

int CapiFrame::GetNumberColumns() {
    return columns.size();
}