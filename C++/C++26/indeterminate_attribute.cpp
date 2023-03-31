void high_performance_processing()
{
    // The compiler will NOT spend time initializing 'buffer' to a safe default.
    // It contains pure, raw, "garbage" memory.
    int buffer[1024] [[indeterminate]]; 

    // You MUST initialize it yourself before reading it
    populate_with_hardware_data(buffer); 

    use_data(buffer[0]);
}