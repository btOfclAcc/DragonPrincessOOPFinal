#include "Inventory.h"

Inventory::Inventory()
{
    inventory = {  };
}

Inventory::~Inventory()
{
}

const vector<Inventory::invenItem> Inventory::GetInventory()
{
    return inventory;
}

void Inventory::SetInventory(vector<invenItem> t_inventory)
{
    inventory = t_inventory;
}

void Inventory::PrintInventory()
{
    system("CLS");
    cout << "===== INVENTORY =====" << endl;
    if (inventory.size() == 0) {
        cout << "Inventory is empty." << endl;
    }
    else {
        bool first = true;
        for (auto invenItem : inventory) {
            if (!first) {
                cout << "---------------------" << endl;
            }
            cout << invenItem.item.GetName() << " x" << invenItem.count << endl;
            cout << invenItem.item.GetDescription() << endl;
            if (invenItem.item.GetUses() > 0) {
                cout << "Uses: " << invenItem.uses << "/" << invenItem.item.GetUses() << endl;
            }
            if (first) {
                first = false;
            }
        }
    }
    cout << "=====================" << endl;
    cout << endl;
}

void Inventory::AddItem(Item t_item)
{
    bool itemFound = false;
    for (auto t_invenItem : inventory) {
        if (t_invenItem.item == t_item) {
            t_invenItem.count += 1;
            itemFound = true;
        }
    }
    if (!itemFound) {
        inventory.push_back(invenItem{ t_item , t_item.GetUses(), 1 });
    }
}

void Inventory::UseItem(Item t_item)
{
    for (auto t_invenItem : inventory) {
        if (t_invenItem.item == t_item) {
            t_invenItem.uses -= 1;
            if (t_invenItem.uses == 0) {
                t_invenItem.count -= 1;
                if (t_invenItem.count == 0) {
                    inventory.erase(remove(inventory.begin(), inventory.end(), t_invenItem), inventory.end());
                }
            }
        }
    }
}