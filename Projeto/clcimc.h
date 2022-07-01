int imc(int x, int y)
{
    int imc;
    imc = x / (y * y);
    if (imc = > 40){
        return 1;
    }
    else if (35 <= imc <= 39.99)
    {
        return 2;
    }
    else if (30 <= imc <= 34.99)
    {
        return 3;
    }
    else if (25 <= imc <= 29.99)
    {
        return 4;
    }
    else if (18.5 <= imc <= 24.9)
    {
        return 5;
    }
    else
    {
        return 6;
    }
}