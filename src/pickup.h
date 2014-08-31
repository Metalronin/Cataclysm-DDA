#ifndef _PICKUP_H_
#define _PICKUP_H_

#include <map>
#include <string>

class Pickup
{
    public:
        Pickup()
        {
            from_veh = false;
        }

        static void do_pickup( point pickup_target, bool from_vehicle, int &offset,
                               std::list<int> &indices, std::list<int> &quantities );
        static void pick_up(int posx, int posy, int min); // Pick up items; ',' or via examine()

    private:
        bool from_veh;

        // Pickup helper functions
        static int interact_with_vehicle( vehicle *veh, int posx, int posy, int veh_root_part );

        static int handle_quiver_insertion(item &here, bool inv_on_fail, int &moves_to_decrement,
                                           bool &picked_up);
        void remove_from_map_or_vehicle(int posx, int posy, vehicle *veh, int cargo_part,
                                        int &moves_taken, int curmit);
        static void show_pickup_message(std::map<std::string, int> mapPickup);
};


#endif //_PICKUP_H_
