//
// Created by sine on 19-1-15.
//

#ifndef SWEETPOTATO_CMTOOLS_H
#define SWEETPOTATO_CMTOOLS_H
/**
 * 字符串是否全是数字
 * @param str
 * @return
 */
bool StrisNum(string str){
    int i;
    for(i=0;i<str.size();i++){
        int tmp=(int)str[i];
        if(tmp>=48&&tmp<=57){
            continue;
        } else{
            return false;
        }
    }
    return true;
}

/**
 * 字符串数字转整数
 * @param str
 * @return
 */
int strNum2Num(string str){
    int i;
    int j=str.size()-1;
    int b=0;
    for(i=0;i<str.size();i++){
        int tmp=(int)str[i];
        int a=tmp-48;
        b=a*pow(10,j)+b;
        j--;
    }
    cout<<"num="<<b<<endl;
    return b;
}
#endif //SWEETPOTATO_CMTOOLS_H
