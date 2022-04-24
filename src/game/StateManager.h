



class StateManager {

    private:
        static StateManager s_instance;
        StateManager();

    public:

        static StateManager& Get();
};



