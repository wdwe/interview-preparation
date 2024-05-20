class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        vis = [False] * len(rooms)
        self.visit(vis, 0, rooms)
        return all(vis)

    def visit(self, vis, room, rooms):
        if not vis[room]:
            vis[room] = True
            for _room in rooms[room]:
                self.visit(vis, _room, rooms)