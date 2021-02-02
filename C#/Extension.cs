namespace Uitilities
{
    public static class NumberExtension
    { 
        #region Const Values
        private const int SECONDS_IN_DAY = 86400;
        private const int SECONDS_IN_HOUR = 3600;
        private const int SECONDS_IN_MIN = 60;
        private const string StandardForm = "{0:N0}";
        #endregion
        public static string InStandard(this int _num)
        {
            return string.Format(StandardForm, _num);
        }
        public static string InStandard(this long _num)
        {
            return string.Format(StandardForm, _num);
        }
        public static string ToKMB(this int _num)
        {
            if(_num == 1000)                    // 1K
                return "1K";
            else if(_num < 10000)               // 9,487
                return string.Format(StandardForm, _num);
            else if(_num < 100000)              // 94.9k
                return string.Format("{0:##,.#K}", _num);
            else if(_num < 1000000)             // 949K
                return string.Format("{0:###,K}", _num);
            else if(_num < 10000000)            // 9.49M
                return string.Format("{0:#,,.##M}", _num);
            else if(_num < 100000000)           // 94.9M
                return string.Format("{0:##,,.#M}", _num);
            else if(_num < 1000000000)          // 949M
                return string.Format("{0:###,,M}", _num);
            else
                return string.Format(StandardForm, _num);
        }
        public static string ToKMBP(this long _num)
        {
            if(_num == 1000)                    // 1K
                return "1K";
            else if(_num < 10000)               // 9,487
                return string.Format(StandardForm, _num);
            else if(_num < 100000)              // 94.9k
                return string.Format("{0:##,.#K}", _num);
            else if(_num < 1000000)             // 949K
                return string.Format("{0:###,K}", _num);
            else if(_num < 10000000)            // 9.49M
                return string.Format("{0:#,,.##M}", _num);
            else if(_num < 100000000)           // 94.9M
                return string.Format("{0:##,,.#M}", _num);
            else if(_num < 1000000000)          // 949M
                return string.Format("{0:###,,M}", _num);
            else if(_num < 10000000000)         // 9.49B
                return string.Format("{0:#,,,.##B}", _num);
            else if(_num < 100000000000)        // 94.9B
                return string.Format("{0:##,,,.#B}", _num);
            else if(_num < 1000000000000)       // 949B
                return string.Format("{0:###,,,B}", _num);
            else if(_num < 10000000000000)      // 9.49P
                return string.Format("{0:#,,,,.##P}", _num);
            else if(_num < 100000000000000)     // 94.9P
                return string.Format("{0:##,,,,.#P}", _num);
            else if(_num < 1000000000000000)    // 949P
                return string.Format("{0:###,,,,P}", _num);
            else
                return string.Format(StandardForm, _num);
        }
    

        public static string ToTime(this int _num, bool _showSign = false)
        {
            int second = (_num >= 0) ? _num : _num*-1;
            int day = (second / SECONDS_IN_DAY);
            second %= SECONDS_IN_DAY;
            int hour = (second / SECONDS_IN_HOUR);
            second %= SECONDS_IN_HOUR;
            int min = (second / SECONDS_IN_MIN);
            second %= SECONDS_IN_MIN;
            
            if(_showSign)
            {
                if(_num >= 0)
                {
                    if(day > 0)
                        return string.Format("+ {0}d {1:00}:{2:00}:{3:00}", day, hour, min, second);
                    else
                        return string.Format("+{0:00}:{1:00}:{2:00}", hour, min, second);
                }
                else
                {
                    if(day > 0)
                        return string.Format("- {0}d {1:00}:{2:00}:{3:00}", day, hour, min, second);
                    else
                        return string.Format("-{0:00}:{1:00}:{2:00}", hour, min, second);
                }
            }
            else
            {
                if(day > 0)
                    return string.Format("{0}d {1:00}:{2:00}:{3:00}", day, hour, min, second);
                else
                    return string.Format("{0:00}:{1:00}:{2:00}", hour, min, second);
            }
        }
        public static string ToTime(this long _num, bool _showSign = false)
        {
            long second = (_num >= 0) ? _num : _num*-1;
            long day = (second / SECONDS_IN_DAY);
            second %= SECONDS_IN_DAY;
            long hour = (second / SECONDS_IN_HOUR);
            second %= SECONDS_IN_HOUR;
            long min = (second / SECONDS_IN_MIN);
            second %= SECONDS_IN_MIN;
            
            if(_showSign)
            {
                if(_num >= 0)
                {
                    if(day > 0)
                        return string.Format("+ {0}d {1:00}:{2:00}:{3:00}", day, hour, min, second);
                    else
                        return string.Format("+{0:00}:{1:00}:{2:00}", hour, min, second);
                }
                else
                {
                    if(day > 0)
                        return string.Format("- {0}d {1:00}:{2:00}:{3:00}", day, hour, min, second);
                    else
                        return string.Format("-{0:00}:{1:00}:{2:00}", hour, min, second);
                }
            }
            else
            {
                if(day > 0)
                    return string.Format("{0}d {1:00}:{2:00}:{3:00}", day, hour, min, second);
                else
                    return string.Format("{0:00}:{1:00}:{2:00}", hour, min, second);
            }
        }
    }
}
