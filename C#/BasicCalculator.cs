using System.Text.RegularExpressions;
using System.Collections.Generic;
using System;

public class BasicCalculator {

    private enum ErrorType
    {
        None = 0,
        NotMatchRx,
        TwoDecimalPoints,
        NoNumberFoundButDecimal,
        RepeatedSign,
        NumberStackIsEmpty,
        DividedByZero,
        UnknownSign,
        LeftPerenthesesNotFound,
        NotAllNumbersOperated,
        NotAllSignsOperated,
    }
    
    private static ErrorType ManipulateOperation(ref Stack<double> _numberStack, ref Stack<char> _signStack, ref List<char> _stoppingChar, bool _removeAtStop = false)
    {
        ErrorType successful = ErrorType.None;

        if (_signStack.Count > 0)
        {
            char nextSign = _signStack.Peek();
            while (successful == ErrorType.None)
            {
                if (_stoppingChar.Contains(nextSign))
                {
                    if (_removeAtStop)
                        _signStack.Pop();

                    break;
                }

                // Stack must contain 2 or more for operation
                if (_numberStack.Count >= 2)
                {
                    double secondNum = _numberStack.Pop();
                    double firstNum = _numberStack.Pop();

                    switch (nextSign)
                    {
                        case '*':
                            _numberStack.Push(firstNum * secondNum);
                            break;
                        case '/':
                            if (secondNum != 0)
                                _numberStack.Push(firstNum / secondNum);
                            else
                                successful = ErrorType.DividedByZero;
                            break;
                        case '^':
                            _numberStack.Push(Math.Pow(firstNum, secondNum));
                            break;
                        case '+':
                            _numberStack.Push(firstNum + secondNum);
                            break;
                        case '-':
                            _numberStack.Push(firstNum - secondNum);
                            break;
                        default:
                            successful = ErrorType.UnknownSign;
                            break;
                    }

                    _signStack.Pop();
                    if (_signStack.Count > 0)
                        nextSign = _signStack.Peek();
                    else
                        break;
                }
                else
                    break;
            }
        }

        return successful;
    }
    private static ErrorType BasicStringCalculator(string _function, Regex _calculatorRx, double _input, out double answer)
    {
        ErrorType isValid = ErrorType.None;
        answer = 0;
        Stack<double> numberStack = new Stack<double>();
        Stack<char> signStack = new Stack<char>();
        List<char> stoppingChar = new List<char>();
        stoppingChar.Add('+'); stoppingChar.Add('-'); stoppingChar.Add('(');
        List<char> stoppingCharForPerentheses = new List<char>();
        stoppingCharForPerentheses.Add('(');

        if (_calculatorRx.IsMatch(_function))
        {
            bool hasNum = false;
            bool hasPeriod = false;
            bool hasSign = false;
            bool isFirstNum = true;
            double currentNum = 0;
            double decimalNum = 0;
            int decimalPlace = 0;

            for (int i = 0; i < _function.Length; i++)
            {
                char word = _function[i];

                // Skip whitespace
                if (word == ' ')
                    continue;
                // It's a Number
                else if (word >= '0' && word <= '9')
                {
                    hasNum = true;
                    hasSign = false;
                    // not in decimal mode
                    if (!hasPeriod)
                    {
                        currentNum *= 10;
                        currentNum += (word - '0');
                    }
                    else
                    {
                        decimalPlace++;
                        decimalNum += Math.Pow(10, -decimalPlace) * (word - '0');
                    }
                }
                // Change to decimal mode
                else if (word == '.')
                {
                    if (!hasPeriod)
                    {
                        hasPeriod = true;
                        hasSign = false;
                    }
                    else
                        isValid = ErrorType.TwoDecimalPoints;
                }
                else
                {
                    // if there is a number push it to stack first
                    if (hasNum)
                    {
                        numberStack.Push(currentNum + decimalNum);
                        currentNum = 0; decimalNum = 0;
                        decimalPlace = 0;
                        hasPeriod = false;
                    }
                    // if there has no number, but a period, then it's invalid
                    else if (hasPeriod)
                    {
                        isValid = ErrorType.NoNumberFoundButDecimal;
                        answer = 0;
                        break;
                    }

                    if (word == '(')
                    {
                        if (hasNum)
                        {
                            hasSign = true;
                            signStack.Push('*');
                            signStack.Push(word);
                        }
                        else
                        {
                            signStack.Push(word);
                        }
                    }
                    else if (word == ')')
                    {
                        isValid = ManipulateOperation(ref numberStack, ref signStack, ref stoppingCharForPerentheses, true);
                    }
                    else if (word == 'x' || word == 'X')
                    {
                        // has operation or is first number => push it as a number directly
                        if (hasSign || isFirstNum)
                        {
                            numberStack.Push(_input);
                        }
                        // no operation => add an extra multiply sign 
                        else
                        {
                            signStack.Push('*');
                            numberStack.Push(_input);
                        }
                        hasSign = false;
                    }
                    else if (word == '^')
                    {
                        if (hasSign)
                            isValid = ErrorType.RepeatedSign;
                        else
                        {
                            hasSign = true;
                            signStack.Push(word);
                        }
                    }
                    else
                    {
                        // Exist extra sign that is not negative
                        if (hasSign && word != '-')
                            isValid = ErrorType.RepeatedSign;
                        else
                        {
                            // operate (Mul / Div / Pow) first
                            isValid = ManipulateOperation(ref numberStack, ref signStack, ref stoppingChar);

                            if (word == '-')
                            {
                                // Exist a number in front, then add it as a negative value
                                if (!isFirstNum)
                                {
                                    hasSign = true;
                                    signStack.Push('+');
                                    signStack.Push('*');
                                    numberStack.Push(-1);
                                }
                                // No number exist, then times -1 to it
                                else
                                {
                                    signStack.Push('*');
                                    numberStack.Push(-1);
                                }
                            }
                            else if (word == '+')
                            {
                                hasSign = true;
                                signStack.Push(word);
                            }
                            else if (word == '*')
                            {
                                hasSign = true;
                                signStack.Push(word);
                            }
                            else if (word == '/')
                            {
                                hasSign = true;
                                signStack.Push(word);
                            }
                            else
                                isValid = ErrorType.UnknownSign;

                            isFirstNum = false;
                        }
                    }

                    hasNum = false;
                }

                if (word != '(')
                    isFirstNum = false;
                else
                    isFirstNum = true;

                if (isValid != ErrorType.None)
                {
                    answer = 0;
                    break;
                }
            }

            if (hasNum)
            {
                numberStack.Push(currentNum + decimalNum);
                currentNum = 0; decimalNum = 0;
                decimalPlace = 0;
                hasPeriod = false;
                hasNum = false;
            }
        }
        else
        {
            isValid = ErrorType.NotMatchRx;
        }

        if (isValid == ErrorType.None)
        {
            stoppingChar.Clear();
            isValid = ManipulateOperation(ref numberStack, ref signStack, ref stoppingChar);

            if (numberStack.Count != 1)
                isValid = ErrorType.NotAllNumbersOperated;
            else if (signStack.Count > 0)
                isValid = ErrorType.NotAllSignsOperated;
            else
                answer = Math.Round(numberStack.Pop(), 6);
        }

        numberStack = null;
        signStack = null;
        stoppingChar = null;
        stoppingCharForPerentheses = null;

        return isValid;
    }
    
    public double Calculate(string s) {
        
        Regex calculatorRx = new Regex(@"^[0-9xX \(\)\.\^\+\-\*/]+$", RegexOptions.Compiled);
        BasicStringCalculator(s, calculatorRx, 1, out double answer);
        return answer;
    }

    
}