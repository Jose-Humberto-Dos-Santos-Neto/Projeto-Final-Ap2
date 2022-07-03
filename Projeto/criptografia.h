char cript(char *palavra)
{
    for (int i=0; palavra[i]!='\0'; i++){
        if((palavra[i]>'A' && palavra[i]<'Z') || (palavra[i]>'a' && palavra[i]<'z') && palavra[i]!=' ' && palavra[i]!='\n' || (palavra[i]>0 && palavra[i]<100000000)){
           palavra[i] = '*';
        }
    } 
}