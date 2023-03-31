void process_data(double x);

template <typename T> void process_data(T) = delete("Implicit conversions are forbidden. You must explicitly pass a double.");

int main()
{
    process_data(3.14);  // OK: exact match for double
    process_data(42);    // Compile Error: "Implicit conversions are forbidden..."
}

///////////////////////////////////////////////////////////////////////////////////////////

class LegacyDatabase
{
	public:
    // Stage 1: Deprecated (C++14 feature)
    // [[deprecated("Use SecureDatabase instead for cryptographic compliance.")]] 
    // void connect();

    // Stage 2: Fully deleted, but with the same clear instructions (C++26)
    void connect() = delete("Use SecureDatabase instead for cryptographic compliance.");
};

///////////////////////////////////////////////////////////////////////////////////////////

class UniqueResourceManager
{
public:
    UniqueResourceManager(const UniqueResourceManager&) = delete("This class manages unique system handles and cannot be safely copied. Use std::move.");
    UniqueResourceManager& operator=(const UniqueResourceManager&) = delete("This class manages unique system handles and cannot be safely copied. Use std::move.");
};