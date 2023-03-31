//////////////////////////////////////////////
// Since C99
//////////////////////////////////////////////

struct Point
{
    int x, y;
};

void draw_point(struct Point p)
{
    printf("Point at (%d, %d)\n", p.x, p.y);
}

int main()
{
    draw_point((struct Point){10, 20});
    return 0;
}

//////////////////////////////////////////////

int sum(int *nums, int count)
{
    int total = 0;
    for (int i = 0; i < count; i++) total += nums[i];
    return total;
}

int main()
{
    int total = sum((int[]){10, 20, 30}, 3);
    printf("Total: %d\n", total);
    return 0;
}

//////////////////////////////////////////////

typedef struct
{
    char *name;
    int power_level;
    bool is_hero;
} Character;

void check_status(Character c)
{
    printf("%s has power %d\n", c.name, c.power_level);
}

int main()
{
    // Only initializing specific fields
	// Others default to zero/null
    check_status((Character){ .name = "Goku", .power_level = 9001 });
    return 0;
}


//////////////////////////////////////////////

void update_config(struct Config *c);

int main()
{
    // Creates a literal and immediately passes its address
    update_config(&(struct Config){ .timeout = 5000, .retry = true });
}