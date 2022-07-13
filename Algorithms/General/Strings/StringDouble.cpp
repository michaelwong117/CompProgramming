string to_string_with_precision(long double m, int prec){
    ostringstream out;
    out << setprecision(prec) << m;
    return out.str();
}