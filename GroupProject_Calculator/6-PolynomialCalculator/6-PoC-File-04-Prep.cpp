#include"6-PoC-File-01-Header.h"
vector<double> AllCoef(const Poly* pol, double pwr) {
    vector<double> coef(pwr + 1, 0.0);
    for (const Item& itm : *pol)
        coef[pwr - itm.second] = itm.first;
    return coef;
}
void NormPolynom(Poly* pol) {
    if (pol->size() == 0)
        return;
    // Привести подобные степени
    auto bgn = begin(*pol);
    while (bgn != end(*pol)) {
        auto p = *bgn;
        double pwr = p.second;
        double cft = p.first;
        auto nxt = bgn; ++nxt;
        while (nxt != end(*pol)) {
            auto q = *nxt;
            if (q.second != pwr)
                ++nxt;
            else {
                cft += q.first;
                nxt = pol->erase(nxt);
            }
        }
        if (cft == p.first)
            ++bgn;
        else {
            p.first = cft;
            auto del = bgn;
            bgn = pol->insert(bgn, p);
            pol->erase(del);;
        }
    }
    // Упорядочить по убыванию степеней
    pol->sort([](Item& p1, Item& p2)
        { return p1.second > p2.second; });
    // Удалить старшие нули
    bgn = begin(*pol);
    while (bgn != end(*pol) && (*bgn).first == 0) {
        pol->erase(bgn);
        bgn = begin(*pol);
    }
}//нормирование полинома(степени х по убыванию)
Poly* GetPolynom(istream& in) {
    Poly* pol = new Poly;
    string line, str1;
    double pwr; double cft;
        getline(in, line);//, '\n');
        istringstream elm1(line);
        while (getline(elm1, str1, ';')) {
            istringstream elm2(str1);
            elm2 >> cft;
            elm2 >> pwr;
            pol->emplace_back(make_pair(cft,pwr));
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
        if (!firstTime && p.first>0)
            cout << "+";
        if (p.first!=0)
        {
            if (p.second==0){ cout << p.first;}
            else{cout << p.first << "*x^" << p.second;}
        }
        firstTime = false;
    }
    cout << "\n";
}
