class CSingleton{
    private:
        CSingleton(){};
    public:
        static CSingleton& getInstance(){
            static CSingleton instance;//c++0x及之后保证locale static 对象的线程安全
            return instance;
        }
};