class BaseSocket {
    int socketId;
 protected:
    static constexpr int invalidSocketId = -1;
    
    BaseSocket(int socketId);
    int getSocketId() const {return socketId;}

 public:
    virtual ~BaseSocket();
    void close();
};

class DataSocket: public BaseSocket {
 public:
    DataSocket(int socketId) : BaseSocket(socketId) {}
    template<typename F>
    std::size_t getMessageData(char* buffer, std::size_t size, F scanForEnd = [](std::size_t){return false;});
    void putMessageData(char const* buffer, std::size_t size);
    void putMessageClose();
};

class ConnectSocket: public DataSocket {
 public:
    ConnectSocket(std::string const& host, int port);
};

class ServerSocket: public BaseSocket {
 public:
    ServerSocket(int port);
    DataSocket accept();
};