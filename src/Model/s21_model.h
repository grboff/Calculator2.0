#ifndef CPP3_SMARTCALC_V2_CALCULATOR_S21_MODEL_H
#define CPP3_SMARTCALC_V2_CALCULATOR_S21_MODEL_H


// #include


namespace s21 {


class ModelValidator {
    public:
    ModelValidator() = default;
    ~ModelValidator() = default;

    //getter

    //setter

    private:
    //variables

    //functions

    // bool
};

class ModelCalculator {
public:
ModelCalculator() = default;
~ModelCalculator() = default;
//getter

//setter

private:
// variables

// functions
};


class Model {
public:
Model() = default;
~Model() = default;
// functions

private:
ModelValidator validator_{};
ModelCalculator calculator_{};
};

} // namespace s21

#endif  // CPP3_SMARTCALC_V2_CALCULATOR_S21_MODEL_H