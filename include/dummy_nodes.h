class ApproachObject : public BT::SyncActionNode
{
  public:
    ApproachObject(const std::string& name) :
        BT::SyncActionNode(name, {})
    {
    }

    // You must override the virtual function tick()
    BT::NodeStatus tick() override
    {
        std::cout << "ApproachObject: " << this->name() << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
};

BT::NodeStatus CheckBattery()
{
    std::cout << "[ Battery: OK ]" << std::endl;
    return BT::NodeStatus::SUCCESS;
}

// We want to wrap into an ActionNode the methods open() and close()
class GripperInterface
{
public:
    GripperInterface(): _open(true) {}

    BT::NodeStatus open() {
        _open = true;
        std::cout << "GripperInterface::open" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }

    BT::NodeStatus close() {
        std::cout << "GripperInterface::close" << std::endl;
        _open = false;
        return BT::NodeStatus::SUCCESS;
    }

private:
    bool _open; // shared information
};
