#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <bitset>
#include <windows.h>

using namespace std;

int getFileSize(const char * fileName){
    ifstream file(fileName, ios::binary | ios::ate);
    int s = file.tellg();
    file.close();
    return s;
}

int getBit(char c, int n){
    return (c >> n)&1;
}
void setBit(unsigned char & c, int n, int b){
    bitset<8> bs (c);
    bs[n] = b;
    c = bs.to_ulong();
}

void flipTheBits(const char * fileName, int n){
    int fileSize = getFileSize(fileName);
    //cout << fileName << " " << fileSize << " bytes" << endl;
    fstream file;
    file.open(fileName);

    for(int i = 0; i < n; i++){

        int flipThisByte = rand() % fileSize;
       // cout << "# " << flipThisByte << endl;

        file.seekg(0);
        file.seekg(flipThisByte);
        unsigned char b = file.peek();
        //file.seekg(flipThisByte-1);

        int bitNum = rand() % 8;
      //  cout << "char Before " << (int)b << " " << b << endl;
      //  cout << "bit# " << bitNum << endl;
      //  cout << "Bit " << getBit(b, bitNum) << !getBit(b, bitNum) << endl;
        setBit(b, bitNum, !getBit(b, bitNum));
      //  cout << "char After " << (int)b << " " << b << endl;

        file.put(b);
    }
//    cout << "image " << getFileSize("image.png") << " bytes" <<endl;

    file.close();

}

int main(int argc, const char* argv[])
{
    srand (time(NULL));
    if(argc < 2)
    {
        cout << "please enter filename, and ensure output directory exists";
        return -1;
    }

    const char * filename = argv[1];

    ifstream in;
    in.open(argv[1]);
   // if(!in.good())
   //     return -1;
    char pwd[250];
    GetCurrentDirectory(250,pwd);
    cout << pwd << endl;
    char temp[300];
    char b[10];
    string a;
    char ita[5];
    string filename_str = string(filename);
    string nn = filename_str.substr(0, filename_str.length()-4);
    string nnend = filename_str.substr(filename_str.length()-3,filename_str.length());
    for(int j = 0; j < 10; j++){
        itoa(j,ita, 10);
        string jj = string(ita);
        for(int i = 0; i <= 10; i++){

            a = string("output/")+string(itoa(i,b,10))+string("_")+nn+jj+"."+nnend;
            CopyFile(filename, a.c_str(), true);
            flipTheBits(a.c_str(), i);
        }


        a = string("output/")+string(itoa(15,b,10))+string("_")+nn+jj+"."+nnend;
        CopyFile(filename, a.c_str(), true);
        flipTheBits(a.c_str(), 15);

        a = string("output/")+string(itoa(20,b,10))+string("_")+nn+jj+"."+nnend;
        CopyFile(filename, a.c_str(), true);
        flipTheBits(a.c_str(), 20);

        a = string("output/")+string(itoa(25,b,10))+string("_")+nn+jj+"."+nnend;
        CopyFile(filename, a.c_str(), true);
        flipTheBits(a.c_str(), 25);

        a = string("output/")+string(itoa(50,b,10))+string("_")+nn+jj+"."+nnend;
        CopyFile(filename, a.c_str(), true);
        flipTheBits(a.c_str(), 50);

        a = string("output/")+string(itoa(100,b,10))+string("_")+nn+jj+"."+nnend;
        CopyFile(filename, a.c_str(), true);
        flipTheBits(a.c_str(), 100);

        a = string("output/")+string(itoa(500,b,10))+string("_")+nn+jj+"."+nnend;
        CopyFile(filename, a.c_str(), true);
        flipTheBits(a.c_str(), 500);

        a = string("output/")+string(itoa(1000,b,10))+string("_")+nn+jj+"."+nnend;
        CopyFile(filename, a.c_str(), true);
        flipTheBits(a.c_str(), 1000);
    }


    //cout << GetLastError() << endl;
    //CopyFile(argv[1], "1/derp2.txt", true);
    //cout << GetLastError() << endl;

    //outf.open("1/1_tester.txt");
   // outf << "test" << endl;
  //  outf.close();
    /*char c = 'a';
    for(int i = 0; i < 8 ; i++)
        cout << getBit(c, i) << " ";

    cout << endl;
    cout <<getBit(c, 3) << endl;
    setBit(c, 3, 1);
    cout <<getBit(c, 3) << endl;

    for(int i = 0; i < 8 ; i++)
        cout << getBit(c, i) << " ";

    cout << endl;
*/

/*


*/
    return 0;
}
