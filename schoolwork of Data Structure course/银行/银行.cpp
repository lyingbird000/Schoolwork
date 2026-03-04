#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

// 业务类型枚举
enum BusinessType {
    PUBLIC_FUND,    // 公积金
    PERSONAL_CARD,  // 个人卡  
    ENTERPRISE_CARD // 企业卡
};

// 客户类
class Customer {
public:
    int number;             // 客户号码
    BusinessType type;      // 业务类型
    time_t arrivalTime;     // 到达时间

    Customer(int num, BusinessType t) : number(num), type(t) {
        arrivalTime = time(nullptr);
    }

    // 安全地获取时间字符串
    string getTimeString() const {
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &arrivalTime);
        return string(buffer);
    }
};

// 窗口类
class Window {
public:
    int id;                 // 窗口编号
    bool isBusy;            // 是否忙碌
    Customer* currentCustomer; // 当前办理的客户
    vector<BusinessType> supportedTypes; // 支持的业务类型

    Window(int windowId, vector<BusinessType> types)
        : id(windowId), isBusy(false), currentCustomer(nullptr), supportedTypes(types) {
    }

    // 开始办理业务
    void serveCustomer(Customer* customer) {
        currentCustomer = customer;
        isBusy = true;
    }

    // 完成业务
    void finishService() {
        delete currentCustomer;
        currentCustomer = nullptr;
        isBusy = false;
    }

    // 检查是否支持某种业务类型
    bool supportsType(BusinessType type) {
        for (BusinessType t : supportedTypes) {
            if (t == type) return true;
        }
        return false;
    }
};

// 银行排队系统类
class BankQueueSystem {
private:
    vector<Window> windows;         // 所有窗口
    queue<Customer*> publicFundQueue;    // 公积金队列
    queue<Customer*> personalCardQueue;  // 个人卡队列
    queue<Customer*> enterpriseCardQueue;// 企业卡队列

    int publicFundCounter = 1;      // 公积金业务计数器
    int personalCardCounter = 1;    // 个人卡业务计数器
    int enterpriseCardCounter = 1;  // 企业卡业务计数器

public:
    BankQueueSystem() {
        // 初始化窗口
        // 1号窗口：公积金
        windows.push_back(Window(1, { PUBLIC_FUND }));
        // 2-4号窗口：个人卡
        for (int i = 2; i <= 4; i++) {
            windows.push_back(Window(i, { PERSONAL_CARD, ENTERPRISE_CARD }));
        }
        // 5-6号窗口：企业卡
        for (int i = 5; i <= 6; i++) {
            windows.push_back(Window(i, { ENTERPRISE_CARD }));
        }
    }

    ~BankQueueSystem() {
        // 清理内存
        while (!publicFundQueue.empty()) {
            delete publicFundQueue.front();
            publicFundQueue.pop();
        }
        while (!personalCardQueue.empty()) {
            delete personalCardQueue.front();
            personalCardQueue.pop();
        }
        while (!enterpriseCardQueue.empty()) {
            delete enterpriseCardQueue.front();
            enterpriseCardQueue.pop();
        }

        for (Window& window : windows) {
            if (window.currentCustomer) {
                delete window.currentCustomer;
            }
        }
    }

    // 客户领号
    void takeNumber(BusinessType type) {
        Customer* customer = nullptr;
        string typeStr;

        switch (type) {
        case PUBLIC_FUND:
            customer = new Customer(publicFundCounter++, type);
            typeStr = "公积金";
            publicFundQueue.push(customer);
            break;
        case PERSONAL_CARD:
            customer = new Customer(personalCardCounter++, type);
            typeStr = "个人卡";
            personalCardQueue.push(customer);
            break;
        case ENTERPRISE_CARD:
            customer = new Customer(enterpriseCardCounter++, type);
            typeStr = "企业卡";
            enterpriseCardQueue.push(customer);
            break;
        }

        cout << "客户领号成功！" << endl;
        cout << "业务类型: " << typeStr << endl;
        cout << "客户号码: " << customer->number << endl;
        cout << "领号时间: " << customer->getTimeString();

        // 尝试分配窗口
        assignWindows();
    }

    // 业务完成
    void finishBusiness(int windowId) {
        if (windowId < 1 || windowId > windows.size()) {
            cout << "无效的窗口编号！" << endl;
            return;
        }

        Window& window = windows[windowId - 1];
        if (!window.isBusy) {
            cout << "窗口 " << windowId << " 当前没有办理业务！" << endl;
            return;
        }

        cout << "窗口 " << windowId << " 业务办理完成！" << endl;
        cout << "客户号码: " << window.currentCustomer->number << endl;

        window.finishService();

        // 重新分配窗口
        assignWindows();
    }

    // 显示所有窗口状态
    void displayStatus() {
        cout << "\n======= 银行窗口状态 =======" << endl;
        cout << "窗口号 | 状态 | 客户号码 | 业务类型" << endl;
        cout << "---------------------------" << endl;

        for (Window& window : windows) {
            cout << setw(4) << window.id << "  | ";
            if (window.isBusy) {
                cout << "忙碌  | ";
                cout << setw(6) << window.currentCustomer->number << "  | ";
                switch (window.currentCustomer->type) {
                case PUBLIC_FUND: cout << "公积金"; break;
                case PERSONAL_CARD: cout << "个人卡"; break;
                case ENTERPRISE_CARD: cout << "企业卡"; break;
                }
            }
            else {
                cout << "空闲  |   --   |   --";
            }
            cout << endl;
        }

        // 显示排队情况
        cout << "\n======= 排队情况 =======" << endl;
        cout << "公积金业务排队: " << publicFundQueue.size() << " 人" << endl;
        cout << "个人卡业务排队: " << personalCardQueue.size() << " 人" << endl;
        cout << "企业卡业务排队: " << enterpriseCardQueue.size() << " 人" << endl;
    }

private:
    // 分配窗口给等待的客户,此处将所有业务放在一个函数里了
    void assignWindows() {
        // 分配公积金业务
        if (!publicFundQueue.empty()) {
            Window& window1 = windows[0]; // 1号窗口
            if (!window1.isBusy) {
                window1.serveCustomer(publicFundQueue.front());
                publicFundQueue.pop();
                cout << "公积金客户 " << window1.currentCustomer->number
                    << " 请在 1 号窗口办理业务！" << endl;
            }
        }

        // 分配个人卡业务
        if (!personalCardQueue.empty()) {
            for (int i = 1; i <= 3; i++) { // 2-4号窗口
                Window& window = windows[i];  //用window修改windows[i]
                if (!window.isBusy) {
                    window.serveCustomer(personalCardQueue.front());
                    personalCardQueue.pop();
                    cout << "个人卡客户 " << window.currentCustomer->number
                        << " 请在 " << window.id << " 号窗口办理业务！" << endl;
                    break;
                }
            }
        }

        // 分配企业卡业务
        if (!enterpriseCardQueue.empty()) {
            // 先尝试5-6号窗口
            for (int i = 4; i <= 5; i++) { // 5-6号窗口
                Window& window = windows[i];
                if (!window.isBusy && window.supportsType(ENTERPRISE_CARD)) {
                    window.serveCustomer(enterpriseCardQueue.front());
                    enterpriseCardQueue.pop();
                    cout << "企业卡客户 " << window.currentCustomer->number
                        << " 请在 " << window.id << " 号窗口办理业务！" << endl;
                    return;
                }
            }

            // 如果5-6号窗口全忙，尝试2-4号窗口
            for (int i = 1; i <= 3; i++) { // 2-4号窗口
                Window& window = windows[i];
                if (!window.isBusy && window.supportsType(ENTERPRISE_CARD)) {
                    window.serveCustomer(enterpriseCardQueue.front());
                    enterpriseCardQueue.pop();
                    cout << "企业卡客户 " << window.currentCustomer->number
                        << " 请在 " << window.id << " 号窗口办理业务！" << endl;
                    return;
                }
            }
        }
    }
};

// 显示菜单
void showMenu() {
    cout << "\n======= 银行排队系统 =======" << endl;
    cout << "1. 公积金业务领号" << endl;
    cout << "2. 个人卡业务领号" << endl;
    cout << "3. 企业卡业务领号" << endl;
    cout << "4. 业务完成" << endl;
    cout << "5. 显示窗口状态" << endl;
    cout << "0. 退出系统" << endl;
    cout << "请选择操作: ";
}

int main() {
    BankQueueSystem bank;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            bank.takeNumber(PUBLIC_FUND);
            break;
        case 2:
            bank.takeNumber(PERSONAL_CARD);
            break;
        case 3:
            bank.takeNumber(ENTERPRISE_CARD);
            break;
        case 4: {
            int windowId;
            cout << "请输入完成业务的窗口号 (1-6): ";
            cin >> windowId;
            bank.finishBusiness(windowId);
            break;
        }
        case 5:
            bank.displayStatus();
            break;
        case 0:
            cout << "感谢使用银行排队系统！" << endl;
            break;
        default:
            cout << "无效的选择，请重新输入！" << endl;
        }
    } while (choice != 0);

    return 0;
}