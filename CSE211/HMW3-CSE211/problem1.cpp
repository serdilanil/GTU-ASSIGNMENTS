#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include<string>

using namespace std;

void readFile(ifstream &file,vector<char>&ch1,vector<vector<char> >&ch2,int &count,int &length);//In this function I read the input file line by line.
void writeFile(ofstream &file2,bool reflexive,bool symmetric,bool antisymmetric,bool transitive,vector<char>&ch1,vector<vector<char> >&ch2,int count,int length,vector<vector<char> >&record);//I print the output file in this function.
bool reflexiveFunc(const vector<char>&ch1,vector<vector<char> >&ch2,int count,int length,vector<vector<char> >&record);//In this function, I find whether the sets have the reflexive property.
bool symmetricFunc(vector<char>&ch1,vector<vector<char> >&ch2,int count,int length,vector<vector<char> >&record);//In this function, I find whether the sets have the symmetric property.
bool antisymmetricFunc( const vector<char>&ch1,const vector<vector<char> >&ch2,int count,int length,vector<vector<char> >&record);//In this function, I find whether the sets have the antisymmetric property.
bool transitiveFunc(vector<char>&ch1,vector<vector<char> >&ch2,int count,int length,vector<vector<char> >&record);//In this function, I find whether the sets have the transitive property.

int main ()
{   
    
    ifstream file;
    file.open("input.txt"); //open the input file.
    vector<char> ch1;    //I open the one dimensional vector for set. 
    vector<vector<char> > ch2; //I open the two dimensional vector To compare individual elements in a set.
    int count,length;
    bool reflexive,symmetric,antisymmetric,transitive;
    vector<vector<char> > record; //Here I use the record vector to move it to the output file.
    ofstream file2;
    file2.open("output.txt");


    while(file.peek() != EOF){

        readFile(file,ch1,ch2,count,length);//In this function I read the "input.txt" and use the input data.
        writeFile(file2,reflexive,symmetric,antisymmetric,transitive,ch1,ch2,count,length,record); //I used the input data and write the wanted data to output.txt.
        record.clear();//because delete the old data.
        
        ch1.clear();//because delete the old data.
        ch2.clear();//because delete the old data.
        
    }

    file.close();
    file2.close();

    return 0;
}

void readFile(ifstream &file,vector<char>&ch1,vector<vector<char> >&ch2,int &count,int &length){//In this function I read the input file line by line.
    
    count=0;
    string line;
    char temp;
    vector<char>element;  //I put the element value to set a limit.

    file >> length;
    file.ignore(1,'\n');

    getline(file,line);   //I use the getline function to read the file line by line.
    istringstream ss (line);

    ss >> temp;
    ch1.push_back(temp); //I'm making room for the ch1 vector here.
    
    for(int i=0;i<(line.length()-(line.length()/2));i++){  //I record the elements which in the set.

        ss >> temp;
        ss >> temp;
        ch1.push_back(temp);
        count++;
    }

        for(int j=0;j<length;j++){   //Here I take and save the two groups one by one.
            file >> temp;
            element.push_back(temp);
            file >> temp;
            file >> temp;
            element.push_back(temp);
            ch2.push_back(element);  //I take the elements in the set one by one and put them into the ch2 vector.
            element.clear();
        }
 
            
}

void writeFile(ofstream &file2,bool reflexive,bool symmetric,bool antisymmetric,bool transitive,vector<char>&ch1,vector<vector<char> >&ch2,int count,int length,vector<vector<char> >&record){
   
    bool result = true;
    char check;
    transitive = false; 
    
    reflexiveFunc(ch1,ch2,count,length,record);  //I call the these functions because I determine the elements which should print the file.
    symmetricFunc(ch1,ch2,count,length,record);        
    transitiveFunc(ch1,ch2,count,length,record);
         
                                //I call the this functions because consisting Poset.
        file2 <<"n"<< endl;    //First,I print the Posets.Then, I process the elements for Hasse diagram. 
        file2 << "POSET: ";
        for (int i = 0; i < ch2.size(); i++)
        { 
            
            file2<< "(";
            
            for (int j = 0; j < 2; j++)
            {
                
                file2 <<ch2[i][j]; 
                    
                    if(j<1){
                        file2<<", ";
                    }
                    
            }  
                file2 << ")";   
            
                if(i<ch2.size()-1)
                {
                        file2<<",";
                }

        } 
            
            file2<<"\n";

            vector<char>recorder(1,0);//Here, make a space of 1 in the vector record and
            vector<char>recorder2(2,0);
    
    for(int i=0;i<ch1.size();i++){ //Here I delete the reflexive elements for Hasse diagram.
        reflexive = false;

        check = ch1[i];

        for(int j=0;j<ch2.size();j++){

            if(ch2[j][0] == check && ch2[j][1] == check){  //Here, if the elements in parentheses are the same (for all elements), a reflexive property is provided.
               
                ch2.erase(ch2.begin() + j);  //I delete by erase function.
                reflexive = true;
            }
        }

    }

        
        for(int i =0;i<ch2.size();i++){  //I am trying to find transitive elements and delete them so no transitive in hasse diagram..
           
            for(int j =0;j<ch2.size();j++){
                
                if(i<ch2.size() && j<ch2.size() && ch2[i][1] == ch2[j][0]){
                    for(int k=0;k<ch2.size();k++){

                        if(ch2[k][0] == ch2[i][0] && ch2[k][1] == ch2[j][1]){
                            i=0,j=0;
                            ch2.erase(ch2.begin()+ k);  //I delete by erase function.
                            transitive = true;
                        }
                    }   

                }
            }
        }
             
         for (int i = 0; i < ch2.size(); i++)  //I write the Hasse diagram in output file.
        { 
            
            for (int j = 0; j < 2; j++)
            {
                
                file2 <<ch2[i][j]; 
                
                if(j<1){
                    file2<<",";
                }
            }  
                file2<<"\n"; 
        }
             
}   
    
bool reflexiveFunc(const vector<char>&ch1,vector<vector<char> >&ch2,int count,int length,vector<vector<char> >&record){
    bool reflexive;
    bool result = true;                  //The aim is to find out if the elements provide reflexive properties.
    char check; 
    vector<char>recorder(1,0);//Here, make a space of 1 in the vector record and
    vector<char>recorder2(2,0);
    for(int i=0;i<count;i++){ //Here I am returning the reflexive property as a boolean value.
        reflexive = false;

        check = ch1[i];

        for(int j=0;j<length && reflexive == false;j++){

            if(ch2[j][0] == check && ch2[j][1] == check){  //Here, if the elements in parentheses are the same (for all elements), a reflexive property is provided.
               recorder[0] = check;
                reflexive = true;
            }
        }
        
                if(reflexive == false){  // if poset doesn't have reflexive I find and consist reflexive.
                    recorder2[0] = check;
                    recorder2[1] = check;
                    ch2.push_back(recorder2); //And I add the reflexive elements for poset rule in this line. 
                    recorder[0] = check;
                    result = false;
                }

    }
            record.push_back(recorder); //And I record the record vector.
            return result;
}

bool symmetricFunc(vector<char>&ch1,vector<vector<char> >&ch2,int count,int length,vector<vector<char> >&record){

    bool symmetric;
    bool result = true;             //The aim is to find out if the elements provide symmetric properties.
    vector<char>recorder(2,0); //Here, make a space of 2 in the vector record and
        
        for(int i =0;i<ch2.size();i++){

            symmetric = false;

            for(int j=0;j<ch2.size();j++){ 

                if(ch2[j][0] == ch2[i][1] && ch2[j][1] == ch2[i][0]){ //I'm looking for the symmetrical property here.
                    recorder[0] = ch2[i][0];
                    recorder[1] = ch2[i][1];
                    if(ch2[i][0] != ch2[i][1]){    //if poset have symmetric ,I ruin the symmetric rule for poset rule. 
                        ch2.erase(ch2.begin() + j);
                    }
                        symmetric = true;  //If it provides the symmetrical property, I return true.
                }

            }            
        
                if(symmetric == false){
                    result = false;
                    recorder[0] = ch2[i][0]; //If it's wrong, I save it to the record vector and send it to the writeFile function.
                    recorder[1] = ch2[i][1];
                }
                    else
                        result = true;

        } 
                record.push_back(recorder);  //I'm making room for the recorder here.
                return result;
}

bool antisymmetricFunc(const vector<char>&ch1,const vector<vector<char> >&ch2,int count,int length,vector<vector<char> >&record){

    bool antisymmetric = true;              //The aim is to find out if the elements provide antisymmetric properties.
    bool result = true;
    vector<char>recorder(2,0);  //Here, make a space of 2 in the vector record and
        
        for(int i =0;i<length && antisymmetric == true && result==true;i++){
            
            antisymmetric = true;

            for(int j=0;j<length && antisymmetric == true;j++){

                if(ch2[j][0] == ch2[i][1] && ch2[j][1] == ch2[i][0] && i!=j){  
                    recorder[0] = ch2[i][0];
                    recorder[1] = ch2[i][1]; 
                    antisymmetric = false; //If a symmetric expression is found I return false.
                }

            }            
                if(antisymmetric == true){ //if antisymmetric rule is true print the terminal elements which in recorder vector.
                    recorder[0] = ch2[i][0];
                    recorder[1] = ch2[i][1];
                    result = true;
                }
                    else
                        result = false;
        } 
                record.push_back(recorder);  //I'm making room for the recorder here.
                return result;
}

bool transitiveFunc(vector<char>&ch1,vector<vector<char> >&ch2,int count,int length,vector<vector<char> >&record){

    bool transitive = false;      
    bool result = true;
    
    vector<char>recorder(4,0),record3(2,0);  //Here, make a space of 4 in the vector record and
                                            
                                //In this function, I scan elements with nested for to find out if they provide transitive properties.

        for(int i =0;i<ch2.size();i++){  //I am trying to find suitable elements for the transitive property in this for loop.
           
            for(int j =0;j<ch2.size();j++){
                
                if(ch2[i][1] == ch2[j][0]){
                    for(int k=0;k<ch2.size();k++){

                        if(ch2[k][0] == ch2[i][0] && ch2[k][1] == ch2[j][1]){
                           
                            transitive = true;
                        }
                    }   

                    if(transitive == false){
                        transitive = true;
                        result = false;
                        recorder[0] = ch2[i][0]; //If I don't find the transitive rule for poset I add the transitive element for rule.
                        recorder[1] = ch2[i][1];
                        recorder[2] = ch2[j][0];
                        recorder[3] = ch2[j][1];
                        record3[0] = ch2[i][0];//I add the this element.
                        record3[1] = ch2[j][1];//I add the this element.
                        ch2.push_back(record3); //I add in this line.
                        record.push_back(recorder);   //I'm making room for the recorder here.
                        return result;
                    }
                        else{

                            transitive = false;
                        }
                }
            }
                
        } 
                return result;
}


