import os
import sys
import time
import json
import time

sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))  # not required after 'pip install uiautomation'
import uiautomation as automation


def DetectZoomMeeting():
    if debug:
        global start
        start = time.time()
    zoomMeetingInProgress = False

    def GetFirstChild(control):
        return control.GetFirstChildControl()

    def GetNextSibling(control):
        return control.GetNextSiblingControl()

    desktop = automation.GetRootControl()
    #window = automation.WindowControl(searchDepth=1, ClassName='ZPContentViewWndClass')
    #toolsMenu = window.WindowControl(searchDepth=3, ClassName='ZPControlPanelClass')
    #start = time.time()
    for control, depth in automation.WalkTree(desktop, getFirstChild=GetFirstChild, getNextSibling=GetNextSibling, includeTop=False, maxDepth=2):
        if debugWalkTree:
            print(str(depth) + ' ' * depth * 4 + str(control))
        if  str(control).find("ZPContentViewWndClass")  > 0 :
            zoomMeetingInProgress = True
    return zoomMeetingInProgress


def GetZoomStatus():
    statusMute = "unknown"
    statusVideo = "unknown"
    statusShare = "unknown"
    statusRecord= "unknown"

    def GetFirstChild(control):
        return control.GetFirstChildControl()

    def GetNextSibling(control):
        return control.GetNextSiblingControl()

    desktop = automation.GetRootControl()
    window = automation.WindowControl(searchDepth=1, ClassName='ZPContentViewWndClass')
    toolsMenu = window.WindowControl(searchDepth=3, ClassName='ZPControlPanelClass')

    if debug:
        print ("desktop="+str(desktop))
        print ("window="+str(window))
        print ("toolsMenu="+str(toolsMenu))

    for control, depth in automation.WalkTree(toolsMenu, getFirstChild=GetFirstChild, getNextSibling=GetNextSibling, includeTop=False, maxDepth=2):
        if debugWalkTree:
            print(str(depth) + ' ' * depth * 4 + str(control))
        if  str(control).find("currently muted")  > 0 :
            statusMute = "muted"
        elif  str(control).find("currently unmuted")  > 0 :
            statusMute = "unmuted"

        elif  str(control).find("start my video")  > 0 :
            statusVideo = "stopped"
        elif  str(control).find("stop my video")  > 0 :
            statusVideo = "started"

        elif  str(control).find("Share Screen")  > 0 :
            statusShare = "stopped"
        elif  str(control).find("Pause Share")  > 0 :
            statusShare = "started"
        elif  str(control).find("Resume Share")  > 0 :
            statusShare = "paused"

 # The maxDepth needs to be increased if you want to add recording status.  However, it doubles the processing time.
 #       elif  str(control).find("Name: Record")  > 0 :
 #           statusRecord = "stopped"
 #       elif  str(control).find("Pause/Stop Recording")  > 0 :
 #           statusRecord = "started"
 #       elif  str(control).find("Resume Share")  > 0 :
 #           statusRecord = "paused"





    if debug:
        stop = time.time()
        print("Elapsed Time:",stop-start)
    statusZoom = "open"


    statusJSON = {
        "statusZoom":statusZoom,
        "statusMute":statusMute,
        "statusVideo":statusVideo,
        "statusShare":statusShare
	}
    y = json.dumps(statusJSON)
    print (y)





def main():
    global debug
    debug = False
    global debugWalkTree
    debugWalkTree = False
    for i in range(0,int(1e25)):
        if DetectZoomMeeting() == True:
            #Zoom Meeting in Progress
            GetZoomStatus()
        else:
            #No Zoom Meeting Detected
            statusJSON = {
                "statusZoom":"closed",
                "statusMute":"muted",
                "statusVideo":"stopped",
                "statusShare":"stopped"
            }
            y = json.dumps(statusJSON)
            print (y)




if __name__ == '__main__':
    main()
