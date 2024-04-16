using System;
using System.Collections.Generic;

public class CurrencyExchange
{
    public bool ExchangeExceed(List<int> _currencyType, Dictionary<int, int> _typeAmount, int _targetAmount, ref Dictionary<int, int> _answer)
    {
        _answer.Clear();

        // nLog(n), n = size of _currentType
        _currencyType.Sort((x, y) => y.CompareTo(x));
        
        // top to down fill up
        foreach(int currency in _currencyType)
        {
            int chooseAmount = _targetAmount / currency;
            if(chooseAmount > 0 && _typeAmount.ContainsKey(currency))
            {
                chooseAmount = (chooseAmount > _typeAmount[currency]) ? _typeAmount[currency] : chooseAmount;
                _answer.Add(currency, chooseAmount);
                _targetAmount -= currency * chooseAmount;
            }
        }        

        for(int i = _currencyType.Count-1; i >= 0; i--)
        {
            if(_targetAmount <= 0)
                break;
            else
            {
                int currency = _currencyType[i];
                int needMoreAmount = (_targetAmount % currency == 0) ? (_targetAmount / currency) : (_targetAmount / currency) + 1;
                if(_typeAmount.ContainsKey(currency))
                {
                    int selectedAmount = 0;
                    bool hasSelected = false;
                    if(_answer.ContainsKey(currency))
                    {
                        selectedAmount = _answer[currency];
                        hasSelected = true;
                    }

                    int leftOverAmount = _typeAmount[currency] - selectedAmount;
                    needMoreAmount = (leftOverAmount >= needMoreAmount) ? needMoreAmount : leftOverAmount;

                    if(hasSelected)
                        _answer[currency] += needMoreAmount;
                    else
                        _answer.Add(currency, needMoreAmount);

                    _targetAmount -= currency * needMoreAmount;
                }
            }
        }

        return _targetAmount <= 0;
    }

    public void ExchangeInLimit(List<int> _currencyType, Dictionary<int, int> _typeAmount, int _targetAmount, ref Dictionary<int, int> _answer)
    {
        _answer.Clear();

        // nLog(n), n = size of _currentType
        _currencyType.Sort((x, y) => y.CompareTo(x));
        
        // top to down fill up
        foreach(int currency in _currencyType)
        {
            int chooseAmount = _targetAmount / currency;
            if(chooseAmount > 0 && _typeAmount.ContainsKey(currency))
            {
                chooseAmount = (chooseAmount > _typeAmount[currency]) ? _typeAmount[currency] : chooseAmount;
                _answer.Add(currency, chooseAmount);
                _targetAmount -= currency * chooseAmount;
            }
        }
    }

}