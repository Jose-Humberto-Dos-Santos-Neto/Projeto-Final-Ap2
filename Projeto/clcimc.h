float clcimc(float x, float y)
{
    float imc;
    imc = x / (y * y);
    if (imc>=40){
        return (int)1;
    }else if(35<=imc && imc<=39.99)
    {
        return (int)2;
    }else if(30<=imc && imc<=34.99)
    {
        return (int)3;
    }else if(25<=imc && imc<=29.99)
    {
        return (int)4;
    }else if (18.5<=imc && imc<=24.9)
    {
        return (int)5;
    }else
    {
        return (int)6;
    }
}