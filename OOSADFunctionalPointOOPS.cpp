#include<iostream>
#include<stdlib.h>
using namespace std;

class functionalPoint{
      private:
          float MeasurementParams[5];
          float functionCounts[5];
          float Qns[14];
          float UAF;
          float VAF;
          float AFP;
          float Budget;
          float NWorkers;
          
      public:
          void getMeasureParams();
          void getAns();
          int getChoice(int toggler, int option);
          void calUAF();
          void VAFcal();
          float AFPcal();
          void calALL(float AFP){
          		float salPerFPPerMonth=8000/6.5;
          		float TotalSalPerMonth=salPerFPPerMonth*AFP;
          		Budget=TotalSalPerMonth;
          		NWorkers=Budget/8000;
		  }
		  void getVals(){
		  	cout<<"\n \t ------------------ REPORT ------------------------";
		  	cout<<"\n\t\tTOTAL BUDGET NEEDED: \t"<<Budget;
		  	cout<<"\n\t\tTOTAL WORKERS NEEDED: \t"<<NWorkers;
		  	cout<<"\n\t -------------------THANK YOU!----------------------";
		  }
		  void getSol();
};

int functionalPoint:: getChoice(int toggler, int option){
     if(toggler==1){
     			 switch(option){
     			 	case 0:
     			 		cout<< "\n FOR EI: \n";
 	                    cout<<"\n Choose one among these and enter the value :\n 1. Simple :3 \n 2. Average  :4 \n 3. Complex :6\n";
     			 		break;
     			 	case 1:
     			 		cout<< "\n FOR EO: \n";
 	                    cout<<"\n Choose one among these and enter the value :\n 1. Simple :4 \n 2. Average  :5 \n 3. Complex :7\n";
     			 		break;
     			 	case 2:
     			 		cout<< "\n FOR EQ: \n";
 	                    cout<<"\n Choose one among these and enter the value :\n 1. Simple :3 \n 2. Average  :4 \n 3. Complex :6\n";
     			 		break;
     			 	case 3:
     			 		cout<< "\n FOR ILF: \n";
 	                    cout<<"\n Choose one among these and enter the value :\n 1. Simple :7 \n 2. Average  :10 \n 3. Complex :15\n";
     			 		break;
     			 	case 4:
     			 		cout<< "\n FOR EIF: \n";
 	                    cout<<"\n Choose one among these and enter the value :\n 1. Simple :5 \n 2. Average  :7 \n 3. Complex :10\n";
     			 		break;
     			 	default:
       			 		break;
     			 		
				  }
                 int val;
                 cin>>val;
                 return val;
     }else{
                 cout<<"\n Rate from 1 to 5 \n";
                 int rate;
                 cin>>rate;
                 
                 if(rate>5){
                 cout<<"invalid ip";
                 exit(0);
                 }
                 return rate; 
     }
     
     }
void functionalPoint:: getMeasureParams(){
     cout<<"\n input the Counts \n";
     for(int i=0;i<5;i++){
     switch(i){
     	case 0: 
     		cout<<"\n no. of EI: \n";
     		break;
     	case 1: 
     		cout<<"\n no. of EO: \n";
     		break;
     	case 2: 
     		cout<<"\n no. of EQ: \n";
			break;     		
     	case 3: 
     		cout<<"\n no. of ILF: \n";
     		break;
     	case 4: 
     		cout<<"\n no. of ELF: \n";
     		break;
     	default:
     		break;
	 }
	 int count;
     cin>>count;
     functionCounts[i]=count;
 	}
 	     
     cout<<"\n Input the Measurement Params Complexity \n for EIs, EOs, EQs, ILFs, EIFs \n\n\n";
     for(int i=0;i<5;i++){
          int val=getChoice(1, i);
          MeasurementParams[i]=val;
         }
	}

void functionalPoint::getAns(){
     cout<<"\n input the rate for 14 qns: \n";
     for(int i=0;i<14;i++){
     		 cout<<"\n Rate for QN:"<<i+1<<"\t";
             int choice=getChoice(100, 100);
             Qns[i]=choice;
             }
    }
void functionalPoint::calUAF(){
    int sum=0;
    for(int i=0;i<5;i++){
            sum+=functionCounts[i]*MeasurementParams[i];
    }
    UAF=sum;
    cout<<"\n UAF="<<UAF <<"\n";
    }
    
void functionalPoint:: VAFcal(){
     float sum=0;
     for(int i=0;i<14;i++){
             sum+=Qns[i];
     }
     VAF=0.65+(sum/100);
     cout<<"\n VAF="<<VAF<<"\n";
     }
     
float functionalPoint:: AFPcal(){
     AFP=UAF*VAF;
     return AFP;
     }

int main(){
    functionalPoint obj;
	obj.getMeasureParams();
	obj.getAns();
	obj.calUAF();
	obj.VAFcal();
	obj.calUAF();
	
	float AFP=obj.AFPcal();
	cout<<"\n AFP= \t"<<AFP<<"\n";
	obj.calALL(AFP);
	obj.getVals();
}
