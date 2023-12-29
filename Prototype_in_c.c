# Blood-Bank-simulation-Project
#include <bits\stdc++.h>
#include<vector>
#include <random>
using namespace std;
vector<int> int_list;
vector<int> int_list2,int_list3;
 unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::minstd_rand0 generator (seed);

int randydonate(int i){
  int dd;
  if(int_list[i+1]==0){
  //default_random_engine generator;
  uniform_int_distribution<int> distribution(int_list[i+2],int_list[i+3]);
  dd=distribution(generator);
  }
  else if(int_list[i+1]==1){
  //default_random_engine generator;
  normal_distribution<double> distribution(int_list[i+2],int_list[i+3]);
  dd=distribution(generator);
  }
  return dd;
}
int randydemand(int i){
  int dd;
 if(int_list2[i+1]==0){
  //default_random_engine generator;
  uniform_int_distribution<int> distribution(int_list2[i+2],int_list2[i+3]);
  dd=distribution(generator);
  }
  else if(int_list2[i+1]==1){
  //default_random_engine generator;
  normal_distribution<double> distribution(int_list2[i+2],int_list2[i+3]);
  dd=distribution(generator);
  }
  return dd;
}
int randyimport(int i){
  int dd;
  if(int_list3[i+1]==0){

  uniform_int_distribution<int> distribution(int_list3[i+2],int_list3[i+3]);
  dd=distribution(generator);
  }
  else if(int_list3[i+1]==1){
  //default_random_engine generator;
  normal_distribution<double> distribution(int_list3[i+2],int_list3[i+3]);
  dd=distribution(generator);
  }
  return dd;
}
int randyreturn(){
  int dd;
  uniform_int_distribution<int> distribution(1,100);
  dd=distribution(generator);
  return dd;
}
int randyevent(int day){
  if(day%15==0){
    return 1;
  }
  return 1;
}
int main()
{
  //cout << "0";
  int donate,i=0,demand,day,k;
  list<int> StockNew,StockOld;
  //cout << "1";
  for(i=0;i<128;i++){
    StockNew.push_back(0);
  }
  list<int> :: iterator it;
  list<int> :: iterator in;
  ifstream myfile;
    list<string> a;
    string line;
    myfile.open ("donate1.txt");
    while(getline(myfile,line)){
    std::istringstream input;
    input.str(line);
       int sum = 0;
    for (std::string line; std::getline(input, line); ) {
        std::istringstream iss(line);
        for (int i; iss >> i;) {
        int_list.push_back(i);
        if (iss.peek() == ',')
            iss.ignore();
              }
       }
      /*  for (int i = 0; i < int_list.size(); i++)
       {
              std::cout << "\n " << int_list.at(i) << "\n";
       }*/

    }
    myfile.close();
  ///////////////////////////////////////////////////////////////////////////////coding input donate
  myfile.open ("demand1.txt");
    while(getline(myfile,line)){
    std::istringstream input;
    input.str(line);
       int sum = 0;
    for (std::string line; std::getline(input, line); ) {
        std::istringstream iss(line);
        for (int i; iss >> i;) {
        int_list2.push_back(i);
        if (iss.peek() == ',')
            iss.ignore();
              }
       }
      /*  for (int i = 0; i < int_list.size(); i++)
       {
              std::cout << "\n " << int_list.at(i) << "\n";
       }*/

    }
    myfile.close();
    ///////////////////////////////////////////////////////////////////////////
    myfile.open ("import1.txt");
    while(getline(myfile,line)){
    std::istringstream input;
    input.str(line);
       int sum = 0;
    for (std::string line; std::getline(input, line); ) {
        std::istringstream iss(line);
        for (int i; iss >> i;) {
        int_list3.push_back(i);
        if (iss.peek() == ',')
            iss.ignore();
              }
       }
      /*  for (int i = 0; i < int_list.size(); i++)
       {
              std::cout << "\n " << int_list.at(i) << "\n";
       }*/

    }
    myfile.close();
////////////////////////////////////////////////////////////////////
   day=0;
    int t=0,w,f,days=0,expire=0,total_stock=0,RealStock=0,shot=0,undo=0;//ติดลบ
    //cout<<"Demand "<<" Donate "<<" Days "<<"   Expire "<<" Export "<<" Need "<<"\n";
  while(days<=110){/*day that simulation */
  //cout << day*4+3 << "\t";
  undo=0;
      if(day==7){
        day=0;
      }
      w = day*4;
     // cout << w << "\t";
      donate = (randydonate(w)+randyimport(w))*randyevent(days);
      demand = randydemand(w);
      undo = randyreturn();
  if(undo<5){
    //cout << donate << "a";
    donate=donate+donate;
  }
      if(donate<0){
        donate =0;
      }
      if(demand <0){
        demand =0;
      }
      cout << demand << "\t" << donate << "\t";
      int y;
      it= StockOld.begin();
      for(i=0;i<StockOld.size();i++){/*Increase blood Age*/
            *it=*it+1;//delete
            it++;
      }
      it= StockNew.begin();
      for(i=0;i<StockNew.size();i++){/*Increase blood Age*/
            if(*it==7){
           // cout << "a" << StockNew.size() << " " <<StockOld.size();
                StockOld.push_front(8);
            }
        //cout << "\t b" << StockNew.size() << " " << StockOld.size() << "\t";
            *it=*it+1;//delete
            it++;
      }
      StockNew.remove(8);
      total_stock=StockNew.size()+StockOld.size();
      StockOld.remove(36);
      RealStock=StockOld.size()+StockNew.size();
      expire = total_stock-StockNew.size()-StockOld.size();
      cout  << days << "\t" << expire << "\t" ;
      for(i=0;i<donate;i++){/*input donate of blood in that day */
          StockNew.push_front(0);
      }
    /*   it= StockNew.begin();
      while(it!=StockNew.end()){/*show blood in the stock */
      /*  cout << (*it);
        it++;
      } */
      f=StockNew.size();
     //cout << StockNew.size() << "\t";;
     /* for(i=0;i<shot;shot--)
      {
          if(!StockOld.empty()){
              StockOld.pop_back();
          }
          else if(!StockNew.empty())
          StockNew.pop_back();
          else
          break;
      }*/
      for(i=0;i<demand;i++){ /*output of blood in that day*/
          if(!StockOld.empty()){
              StockOld.pop_back();
          }
          else if(!StockNew.empty())
          StockNew.pop_back();
      }
     // cout << "\n";
      /*t= StockNew.begin();
     /*  while(it!=StockNew.end()){/*show total at that day */
       /*cout << (*it);
        it++;
      } */
       day++;
       t++; //cout << t << "\t";
      /*if(demand > f){
        cout<< f;
      }
      else{
      cout << StockNew.size();
      }*/
      RealStock = RealStock+donate-demand;
      if(RealStock<0)
      {
           RealStock=0;
           shot=shot+demand-donate;
      }
      cout << RealStock << "\t" << shot;
      cout << "\n";
      days++;
  }
    return 0;
}//ขาดรายวัน.คืนกลับมาเพ.ิ่มdonate*
