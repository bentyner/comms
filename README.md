# comms
Minimal experimental embedded http client with dbus signaling interface.

$ comms &

$ busctl emit /foo/bar/hello foo.bar.hello hello /redfish/v1

$ busctl emit /foo.bar/hello foo.bar.hello hello stop
