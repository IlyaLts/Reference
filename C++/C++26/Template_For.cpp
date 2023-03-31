template<typename... Args> void print(Args&&... args)
{
    template for (auto arg : args)
    {
        std::cout << arg << '\n';
    }
}