//
//  ofxScrollView.h
//  Created by Lukasz Karluk on 2/06/2014.
//

#pragma once

#include "ofMain.h"

//--------------------------------------------------------------
class ofxScrollView {
    
public:
    
    ofxScrollView();
    ~ofxScrollView();

    virtual void setup();
    void setWindowRect(const ofRectangle & rect);
    void setContentRect(const ofRectangle & rect);
    void setScrollEasing(float value);
    void setScrollPosition(float x=0, float y=0, bool bEase=true);
    void setUserInteraction(bool bEnable);
    const ofRectangle & getWindowRect();
    const ofRectangle & getContentRect();
    const ofVec2f & getScrollPosition();
    const ofMatrix4x4 & getMatrix();
    
    ofRectangle transformRect(const ofRectangle & rect, const ofMatrix4x4 & mat);
    ofVec2f screenPointToContentPoint(const ofVec2f & screenPoint);
    
    virtual void update();

    virtual void begin();
    virtual void end();
    virtual void draw();
    
    virtual void exit();
    
    virtual void dragDown(int x, int y, int id);
    virtual void dragMoved(int x, int y, int id);
    virtual void dragUp(int x, int y, int id);
    virtual void dragCancel();
    
    virtual void zoomDown(int x, int y, int id);
    virtual void zoomMoved(int x, int y, int id);
    virtual void zoomUp(int x, int y, int id);
    virtual void zoomCancel();
    
    bool bNeedsToReset;
    bool bUserInteractionEnabled;
    
    ofRectangle windowRect;
    ofRectangle contentRect;
    ofRectangle scrollRect;
    ofVec2f scrollSize;
    ofVec2f scroll;
    ofVec2f scrollDown;
    ofVec2f scrollEased;
    float scrollEasing;
    
    ofVec2f dragDownPos;
    ofVec2f dragMovePos;
    ofVec2f dragMovePosPrev;
    ofVec2f dragVel;
    int dragID;
    bool bDragging;
    bool bDraggingChanged;
    
    ofVec2f zoomDownScreenPos;
    ofVec2f zoomMoveScreenPos;
    ofVec2f zoomDownContentPos;
    int zoomID;
    bool bZooming;
    bool bZoomingChanged;
    
    float scale;
    float scaleDown;
    float scaleMin;
    float scaleMax;
    ofMatrix4x4 mat;
    
    //----------------------------------------------------------
    virtual void mouseMoved(ofMouseEventArgs & mouse){
        mouseMoved(mouse.x,mouse.y);
    }
    virtual void mouseDragged(ofMouseEventArgs & mouse){
        mouseDragged(mouse.x,mouse.y,mouse.button);
    }
    virtual void mousePressed(ofMouseEventArgs & mouse){
        mousePressed(mouse.x,mouse.y,mouse.button);
    }
    virtual void mouseReleased(ofMouseEventArgs & mouse){
        mouseReleased(mouse.x,mouse.y,mouse.button);
    }
    
    virtual void mouseMoved( int x, int y);
    virtual void mouseDragged( int x, int y, int button);
    virtual void mousePressed( int x, int y, int button);
    virtual void mouseReleased(int x, int y, int button);
    
    //----------------------------------------------------------
	virtual void touchDown(ofTouchEventArgs &touch) {
        touchDown(touch.x, touch.y, touch.id);
    }
	virtual void touchMoved(ofTouchEventArgs &touch) {
        touchMoved(touch.x, touch.y, touch.id);
    }
	virtual void touchUp(ofTouchEventArgs &touch) {
        touchUp(touch.x, touch.y, touch.id);
    }
    virtual void touchDoubleTap(ofTouchEventArgs &touch) {
        touchDoubleTap(touch.x, touch.y, touch.id);
    }
    virtual void touchCancelled(ofTouchEventArgs &touch) {
        touchCancelled(touch.x, touch.y, touch.id);
    }
    
    virtual void touchDown(int x, int y, int id);
    virtual void touchMoved(int x, int y, int id);
    virtual void touchUp(int x, int y, int id);
    virtual void touchDoubleTap(int x, int y, int id);
    virtual void touchCancelled(int x, int y, int id);

};