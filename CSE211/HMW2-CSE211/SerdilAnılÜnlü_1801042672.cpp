#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include<string>

using namespace std;

void readFile(ifstream &file,vector<char>&ch1,vector<vector<char> >&ch2,int &count,int &length);//In this function I read the input file line by line.
void writeFile(ofstream &file2,bool reflexive,bool symmetric,bool antisymmetric,bool transitive,vector<vector<char> >&record); //I print the result of the elements I processed in this function to the output.txt file.
bool reflexiveFunc(const vector<char>&ch1,const vector<vector<char> >&ch2,int count,int length,vector<vector<char> >&record);//In this function, I find whether the sets have the reflexive property.
bool symmetricFunc(const vector<char>&ch1,const vector<vector<char> >&ch2,int count,int length,vector<vector<char> >&record);//In this function, I find whether the sets have the symmetric property.
bool antisymmetricFunc(const vector<char>&ch1,const vector<vector<char> >&ch2,int count,int length,vector<vector<char> >&record);//In this function, I find whether the sets have the antisymmetric property.
bool transitiveFunc(const vector<char>&ch1,const vector<vector<char> >&ch2,int count,int length,vector<vector<char> >&record);//In this function, I find whether the sets have the transitive property.


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

        readFile(file,ch1,ch2,count,length);
                                                    //Here I assign the returned value.
        reflexive =  reflexiveFunc(ch1,ch2,count,length,record);
        symmetric = symmetricFunc(ch1,ch2,count,length,record);
        antisymmetric = antisymmetricFunc(ch1,ch2,count,length,record);
        transitive = transitiveFunc(ch1,ch2,count,length,record);
        writeFile(file2,reflexive,symmetric,antisymmetric,transitive,record); //I print the output file according to the values I assign here.
        record.clear();
        
        ch1.clear();
        ch2.clear();
        
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
    
    for(int i=0;i<(line.length()-(line.length()/2));i++){  

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

void writeFile(ofstream &file2,bool reflexive,bool symmetric,bool antisymmetric,bool transitive,vector<vector<char> >&record){
    
    file2 << "n" << endl;            //I print the result of the elements I processed in this function to the output.txt file.
                                    //Here, I write to the output file whether the elements I have recorded in the record vector meet the properties.
    if(reflexive == true){          //If it provides that feature, I print yes, i fit does not, I print no with the reason with the vectors I recorded the elements.
                                    //The double array record holds the elements.

        file2 << "Reflexive: Yes, all elements are present." << endl;
    }
        else{
            file2 << "Reflexive: No,because (" <<record[0][0]<< "," <<record[0][0]<<") is not found." <<endl;

        }
        
    if(symmetric == true){

         file2 << "Symmetric: Yes, because (" << record[1][0] << "," << record[1][1]<< ")" <<" is found where (" <<record[1][1]<<","<< record[1][0]<<") is found and other values provide this rule."<<endl;
    }

        else{
            file2 << "Symmetric: No,because ("<<record[1][0] << "," << record[1][1] << ")" << " is found whereas ("<< record[1][1]<< ","<< record[1][0] << ") is not found."<<endl;

        }

    if(antisymmetric == true){

         file2 << "Antisymmetric: Yes, because ("<<record[1][0] << "," << record[1][1] << ")" << " is found whereas ("<< record[1][1]<< ","<< record[1][0] << ") is not found and other values provide this rule."<< endl;
    }

        else{
            
            file2 << "Antisymmetric: No, because ("<<record[2][0] << "," << record[2][1] << ")" << " is found whereas ("<<  record[2][1] <<","<<record[2][0]<< ") is found." <<endl;

        }

    if(transitive == true){

         file2 << "Transitive: Yes, all elements providing this rule."<< endl;
    }

        else{
            file2 << "Transitive: No,because ("<<record[3][0] << "," << record[3][3] << ") is not found where (" << record[3][0] << "," << record[3][1] << ")"<< " and ("<< record[3][1]<<","<<record[3][3]<< ") are found."<<endl;

        }

}   
    
bool reflexiveFunc(const vector<char>&ch1,const vector<vector<char> >&ch2,int count,int length,vector<vector<char> >&record){
    bool reflexive;
    bool result = true;         //The aim is to find out if the elements provide reflexive properties.
    char check; 
    vector<char>recorder(1,0);//Here, make a space of 1 in the vector record and

    for(int i=0;i<count && result == true;i++){ //Here I am returning the reflexive property as a boolean value.
        reflexive = false;

        check = ch1[i];

        for(int j=0;j<length && reflexive == false;j++){

            if(ch2[j][0] == check && ch2[j][1] == check){  //Here, if the elements in parentheses are the same (for all elements), a reflexive property is provided.
               recorder[0] = check;
                reflexive = true;
            }
        }
        
                if(reflexive == false){  // if doesn't provide I return false value.
                    result = false;
                    recorder[0] = check;
                }

    }
            record.push_back(recorder); //And I record the record vector.
            return result;
}

bool symmetricFunc(const vector<char>&ch1,const vector<vector<char> >&ch2,int count,int length,vector<vector<char> >&record){

    bool symmetric;
    bool result = true;             //The aim is to find out if the elements provide symmetric properties.
    vector<char>recorder(2,0); //Here, make a space of 2 in the vector record and
        
        for(int i =0;i<length && result == true;i++){

            symmetric = false;

            for(int j=0;j<length && result == true && symmetric == false;j++){ 

                if(ch2[j][0] == ch2[i][1] && ch2[j][1] == ch2[i][0]){ //I'm looking for the symmetrical property here.
                    recorder[0] = ch2[i][0];
                    recorder[1] = ch2[i][1];
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

bool transitiveFunc(const vector<char>&ch1,const vector<vector<char> >&ch2,int count,int length,vector<vector<char> >&record){

    bool transitive = false;      
    bool result = true;
    vector<char>recorder(4,0);  //Here, make a space of 4 in the vector record and
                                            
                                //In this function, I scan elements with nested for to find out if they provide transitive properties.

        for(int i =0;i<length && result == true;i++){  //I am trying to find suitable elements for the transitive property in this for loop.
           
            for(int j =0;j<length && result == true;j++){
                
                if(ch2[i][1] == ch2[j][0]){
                    for(int k=0;k<length && transitive == false;k++){

                        if(ch2[k][0] == ch2[i][0] && ch2[k][1] == ch2[j][1]){
                           
                            transitive = true;
                        }
                    }   

                    if(transitive == false){
                        result = false;
                        recorder[0] = ch2[i][0]; //If I can't find the transitive property, I return false and save it to the record vector and print it.
                        recorder[1] = ch2[i][1];
                        recorder[2] = ch2[j][0];
                        recorder[3] = ch2[j][1];
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