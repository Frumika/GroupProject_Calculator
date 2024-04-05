#include"6-PoC-File-01-Header.h"
vector<double> AllCoef(const Poly* pol, double pwr) {
    vector<double> coef(pwr + 1, 0.0);
    for (const Item& itm : *pol)
        coef[pwr - itm.first] = itm.second;
    return coef;
}
Poly* GetPolynom(istream& in) {
    Poly* pol = new Poly;
    string line, str1;
    double pwr; double cft;
    getline(in, line);//, '\n');
    istringstream elm1(line);
    while (getline(elm1, str1, ';')) {
        istringstream elm2(str1);
        elm2 >> pwr;
        elm2 >> cft;
        pol->emplace_back(make_pair(pwr, cft));
    }
    return pol;
}
void PrintPolynom(Poly* pol) {
    if (pol->size() == 0) {
        cout << 0 << "\n";
        return;
    }
    bool firstTime = true;
    for (Item& p : *pol) {
        if (!firstTime)
            cout << "+";
        if (p.second!=0)
        {
            if (p.first==0){ cout << p.second;}
            else{cout << p.second << "*x^" << p.first;}
        }
        firstTime = false;
    }
    cout << "\n";
}

void NormPolynom(Poly* pol) {
    if (pol->size() == 0)
        return;
    // Привести подобные степени
    auto bgn = begin(*pol);
    while (bgn != end(*pol)) {
        auto p = *bgn;
        double pwr = p.first;
        double cft = p.second;
        auto nxt = bgn; ++nxt;
        while (nxt != end(*pol)) {
            auto q = *nxt;
            if (q.first != pwr)
                ++nxt;
            else {
                cft += q.second;
                nxt = pol->erase(nxt);
            }
        }
        if (cft == p.second)
            ++bgn;
        else {
            p.second = cft;
            auto del = bgn;
            bgn = pol->insert(bgn, p);
            pol->erase(del);;
        }
    }
    // Упорядочить по убыванию степеней
    pol->sort([](Item& p1, Item& p2)
        { return p1.first > p2.first; });
    // Удалить старшие нули
    bgn = begin(*pol);
    while (bgn != end(*pol) && (*bgn).second == 0) {
        pol->erase(bgn);
        bgn = begin(*pol);
    }
}//нормирование полинома(степени х по убыванию)