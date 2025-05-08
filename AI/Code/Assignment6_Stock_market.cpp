#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Define the structure to store stock data
struct StockData
{
    string symbol;
    double currentPrice;
    int volume;
    vector<double> prices; // Vector to store prices for moving average and RSI calculation
};

// Class for calculating technical indicators
class StockTechnicalIndicators
{
public:
    // Function to calculate the Simple Moving Average (SMA) over a given window
    double calculateSMA(const vector<double> &prices, int window)
    {
        if (prices.size() < window)
        {
            cout << "Not enough data for SMA calculation!" << endl;
            return 0;
        }
        double sum = 0;
        for (int i = prices.size() - window; i < prices.size(); i++)
        {
            sum += prices[i];
        }
        return sum / window;
    }

    // Function to calculate the Relative Strength Index (RSI)
    double calculateRSI(const vector<double> &prices, int period = 14)
    {
        if (prices.size() < period + 1)
        {
            cout << "Not enough data for RSI calculation!" << endl;
            return 0;
        }

        double gain = 0, loss = 0;
        for (int i = prices.size() - period; i < prices.size() - 1; i++)
        {
            double change = prices[i + 1] - prices[i];
            if (change > 0)
            {
                gain += change;
            }
            else
            {
                loss -= change;
            }
        }

        double avgGain = gain / period;
        double avgLoss = loss / period;

        double rs = avgGain / avgLoss;
        return 100 - (100 / (1 + rs));
    }
};

// Expert system class to evaluate stock data
class StockExpertSystem
{
public:
    StockTechnicalIndicators techIndicators;

public:
    // Function to evaluate whether the stock should be bought, sold, or held
    string evaluateStockDecision(const StockData &stock)
    {
        // Calculate SMA and RSI
        double sma = techIndicators.calculateSMA(stock.prices, 10); // Using a 10-day window for SMA
        double rsi = techIndicators.calculateRSI(stock.prices);

        cout << "SMA: " << sma << ", RSI: " << rsi << endl;

        // Rule-based decision system
        if (stock.currentPrice > sma && rsi < 70)
        {
            return "Buy"; // Buy when price is higher than SMA and RSI is not overbought
        }
        else if (stock.currentPrice < sma && rsi > 70)
        {
            return "Sell"; // Sell when price is lower than SMA and RSI is overbought
        }
        else
        {
            return "Hold"; // Otherwise, hold the stock
        }
    }
};

int main()
{
    StockData stock1;
    int choice;

    // Taking user input
    cout << "Enter stock symbol: ";
    cin >> stock1.symbol;

    cout << "Enter current stock price: ";
    cin >> stock1.currentPrice;

    cout << "Enter stock volume: ";
    cin >> stock1.volume;

    int numPrices;
    cout << "Enter the number of past prices for analysis: ";
    cin >> numPrices;

    stock1.prices.resize(numPrices);

    // Taking past stock prices as input for analysis
    cout << "Enter the past stock prices: ";
    for (int i = 0; i < numPrices; i++)
    {
        cin >> stock1.prices[i];
    }

    StockExpertSystem expertSystem;

    do
    {
        // Display menu
        cout << "\nStock Market Trading Expert System Menu:" << endl;
        cout << "1. Evaluate Stock Decision" << endl;
        cout << "2. Calculate Moving Average (SMA)" << endl;
        cout << "3. Calculate RSI" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // Evaluate the stock decision
            string decision = expertSystem.evaluateStockDecision(stock1);
            cout << "Stock " << stock1.symbol << " Decision: " << decision << endl;
            break;
        }
        case 2:
        {
            // Calculate the 10-day Simple Moving Average (SMA)
            double sma = expertSystem.techIndicators.calculateSMA(stock1.prices, 10);
            cout << "Stock " << stock1.symbol << " 10-Day SMA: " << sma << endl;
            break;
        }
        case 3:
        {
            // Calculate the Relative Strength Index (RSI)
            double rsi = expertSystem.techIndicators.calculateRSI(stock1.prices);
            cout << "Stock " << stock1.symbol << " RSI: " << rsi << endl;
            break;
        }
        case 4:
            cout << "Exiting the system..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}