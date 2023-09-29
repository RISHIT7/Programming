/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "ulimitedrational.h"

int Greater(UnlimitedInt *n1, UnlimitedInt *n2)
{
    if (n1->get_size() > n2->get_size())
    {
        return 1; // greater than
    }
    else if (n1->get_size() < n2->get_size())
    {
        return 0; // less than
    }

    int *n1_u = n1->get_array();
    int *n2_u = n2->get_array();
    for (int i = 0; i < n1->get_size(); i++)
    {
        if (n1_u[i] > n2_u[i])
        {
            return 1; // greater than
        }
        else if (n1_u[i] < n2_u[i])
        {
            return 0; // less than
        }
    }
    return -1; // equal
}

UnlimitedInt *gcd(UnlimitedInt *p, UnlimitedInt *q)
{
    // UnlimitedInt *one = new UnlimitedInt(1);
    // if (Greater(p, q) == 1)
    // {
    //     UnlimitedInt *result = new UnlimitedInt(q->get_array(), q->get_capacity(), 1, q->get_size());
    //     while (result->get_sign() > 0)
    //     {
    //         if (p->mod(p, result)->get_sign() == 0 && q->mod(q, result)->get_sign() == 0)
    //         {
    //             break;
    //         }
    //         result = result->sub(result, one);
    //     }

    //     return result;
    // }

    // if (Greater(p, q) == 0)
    // {
    //     UnlimitedInt *result = new UnlimitedInt(p->get_array(), p->get_capacity(), 1, p->get_size());
    //     while (result->get_sign() > 0)
    //     {
    //         if (p->mod(p, result)->get_sign() == 0 && q->mod(q, result)->get_sign() == 0)
    //         {
    //             break;
    //         }
    //         result = result->sub(result, one);
    //     }

    //     return result;
    // }

    // if (Greater(p, q) == -1)
    // {
    //     UnlimitedInt *result = new UnlimitedInt(p->get_array(), p->get_capacity(), 1, p->get_size());

    //     return result;
    // }

    while (q->get_sign() != 0)
    {
        UnlimitedInt *ass = q;
        q = UnlimitedInt::mod(p, q);
        p = ass;
    }
    return p;
}

UnlimitedRational::UnlimitedRational()
{
    p = new UnlimitedInt();
    q = new UnlimitedInt();
}

UnlimitedRational::UnlimitedRational(UnlimitedInt *num, UnlimitedInt *den)
{
    p = new UnlimitedInt(num->get_array(), num->get_capacity(), num->get_sign(), num->get_size());
    q = new UnlimitedInt(den->get_array(), den->get_capacity(), den->get_sign(), den->get_size());

    if ((p->get_size() == 1 && p->get_array()[0] == 0) && (q->get_size() == 1 && q->get_array()[0] == 0))
    {
        continue;
    }
    else
    {
        UnlimitedInt *g = gcd(p, q);
        p = p->div(p, g);
        q = q->div(q, g);
        delete g;
    }
}

UnlimitedRational::~UnlimitedRational()
{
    delete p;
    delete q;
}

UnlimitedInt *UnlimitedRational::get_p()
{
    return p;
}

UnlimitedInt *UnlimitedRational::get_q()
{
    return q;
}

string UnlimitedRational::get_p_str()
{
    return p->to_string();
}

string UnlimitedRational::get_q_str()
{
    return q->to_string();
}

string UnlimitedRational::get_frac_str()
{
    string result;
    result.append(p->to_string());
    result.append("/");
    result.append(q->to_string());
    return result;
}

UnlimitedRational *UnlimitedRational::add(UnlimitedRational *i1, UnlimitedRational *i2)
{
    UnlimitedInt *numerator = new UnlimitedInt();
    UnlimitedInt *numerator_t1 = new UnlimitedInt();
    UnlimitedInt *numerator_t2 = new UnlimitedInt();

    numerator_t1 = numerator_t1->mul(i1->get_p(), i2->get_q());
    numerator_t2 = numerator_t2->mul(i1->get_q(), i2->get_p());
    numerator = numerator->add(numerator_t1, numerator_t2);
    delete numerator_t1;
    delete numerator_t2;

    UnlimitedInt *denominator = new UnlimitedInt();
    denominator = denominator->mul(i1->get_q(), i2->get_q());

    UnlimitedRational *result = new UnlimitedRational(numerator, denominator);
    delete numerator;
    delete denominator;

    return result;
}

UnlimitedRational *UnlimitedRational::sub(UnlimitedRational *i1, UnlimitedRational *i2)
{
    UnlimitedInt *numerator = new UnlimitedInt();
    UnlimitedInt *numerator_t1 = new UnlimitedInt();
    UnlimitedInt *numerator_t2 = new UnlimitedInt();

    numerator_t1 = numerator_t1->mul(i1->get_p(), i2->get_q());
    numerator_t2 = numerator_t2->mul(i1->get_q(), i2->get_p());
    numerator = numerator->sub(numerator_t1, numerator_t2);
    delete numerator_t1;
    delete numerator_t2;

    UnlimitedInt *denominator = new UnlimitedInt();
    denominator = denominator->mul(i1->get_q(), i2->get_q());

    UnlimitedRational *result = new UnlimitedRational(numerator, denominator); // BT with GCD

    delete numerator;
    delete denominator;

    return result;
}

UnlimitedRational *UnlimitedRational::mul(UnlimitedRational *i1, UnlimitedRational *i2)
{
    UnlimitedInt *numerator = new UnlimitedInt();

    numerator = numerator->mul(i1->get_p(), i2->get_p());

    UnlimitedInt *denominator = new UnlimitedInt();
    denominator = denominator->mul(i1->get_q(), i2->get_q());

    UnlimitedRational *result = new UnlimitedRational(numerator, denominator); // BT with GCD

    delete numerator;
    delete denominator;

    return result;
}

UnlimitedRational *UnlimitedRational::div(UnlimitedRational *i1, UnlimitedRational *i2)
{
    UnlimitedInt *numerator = new UnlimitedInt();

    numerator = numerator->mul(i1->get_p(), i2->get_q());

    UnlimitedInt *denominator = new UnlimitedInt();
    denominator = denominator->mul(i1->get_q(), i2->get_p());

    UnlimitedRational *result = new UnlimitedRational(numerator, denominator); // BT with GCD

    delete numerator;
    delete denominator;

    return result;
}

int main()
{
    UnlimitedInt *five = new UnlimitedInt(5);
    UnlimitedInt *ten = new UnlimitedInt(10);

    UnlimitedInt *six = new UnlimitedInt(6);
    UnlimitedInt *seven = new UnlimitedInt(7);

    UnlimitedRational *num1 = new UnlimitedRational(five, ten);
    UnlimitedRational *num2 = new UnlimitedRational(six, seven);

    UnlimitedRational *add = num1->div(num1, num2);
    cout << add->get_frac_str() << endl;

    return 0;
}