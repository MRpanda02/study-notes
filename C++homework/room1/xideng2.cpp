#include <memory>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;
void SetValue(int s,int j,char &c)//����ĳһ��λ�õ�ֵ��
{
    if(s){//�����1
        c = c|(1<<j);
    }
}


int GetValue(const char c,int j)//��ȡĳһ��λ�õ�ֵ��
{
    return (c>>j)&1;

}


void GetOppose(char &c,int j)//��ĳһ��λ�õ�ֵ��ȡ����
{
    c = c^(1<<j);


}


void print(char c[],int t)
{

    cout << "PUZZLE #" << t << endl;

    for( int i = 0;i<5;i++){
//        for( int  j = 5; j>=0; j-- ){
        for(int j = 0;j<6;j++){
            cout << GetValue(c[i], j)<<" ";
        }
        cout<<endl;
    }

}




int main()
{
    char Oriligths[5] = {0};//ԭʼ��Ϩ��״̬
    char Ligths[5] = {0};//�仯�еĵƵ�Ϩ��״̬
    char Result[5] = {0};//���Ľ���������ص�״̬��
    char flag ;//ÿ�п��ص�״̬��;
    int caseNO = 0;
    cin>>caseNO;

     for(int t = 1;t<=caseNO;t++){
        memset(Oriligths,0,sizeof(Oriligths));//���ԭ��������ռ��е�����
        for(int i = 0;i<5;i++){
            for(int j = 0;j<6;j++){

                int s= 0;
                cin>>s;
                SetValue(s, j, Oriligths[i]); //��ֵ�Ž�char����ֽڵ���Ӧ��λ���ϣ�
            }
        }//���������

        for( int n = 0;n<64;n++){//64�����ÿһ�ֶ�һ��һ��ö��
            memcpy(Ligths, Oriligths, sizeof(Oriligths));//����chu_chi_biao������Ϊ���ĳ�ʼ״̬
            flag = n;//��ʾ��һ�п��ص�״̬��


            for(int i = 0;i<5;i++){
                Result[i] = flag;//����һ�еĿ��ص�״̬��������һ�еĿ���״̬�����

                for(int j = 0;j<6;j++){
                    if(GetValue(flag,j)){//����ط�����״̬��ֵ��1
                        if(j>0)
                            GetOppose(Ligths[i], j-1);      //�ı�����Ƶ���ߵĵ�Ϩ��״̬��
                        if(j<5)
                            GetOppose(Ligths[i],j+1);   //�ı�����Ƶ��ұߵĵ�Ϩ��״̬��
                        GetOppose(Ligths[i], j);       //�ı䵱ǰ��Ϩ��״̬��
                    }

                }//��i�еĿ���״̬��Ϩ��״̬ȷ����
                if(i<4){
                    Ligths[i+1] ^= flag;     //�Ƚ���һ�иı��ֵ���б仯��
                }
                flag = Ligths[i];   //��һ�еĿ���״̬Ҳȷ����;
            }
                //            �ж����һ���ǲ��Ƕ�Ϊ0;�Ǿ��Ǵ�ӡResult��ֵ�����Ǿͼ�����һ�����裻
            if(Ligths[4]==0){
                print(Result,t);
                break;
            }

        }
    }
    return 0;


}


