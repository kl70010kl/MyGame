﻿/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{

    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first

    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }
	sprite = Sprite::create("sample06.png");
	sprite2 = Sprite::create("HelloWorld.png");
	//                        X       Y
	sprite->setPosition(Vec2(visibleSize.width/2.0f, visibleSize.height/2.0f));

	
	//图片的左下变为基准点(0,0)  中心(0.5f,0.5f) 右上(1.0f,1.0f)
	sprite->setAnchorPoint(Vec2(0.5f, 0.5f));

	sprite->setScale(4.0f);

	sprite->getTexture()->setAliasTexParameters();
	//sprite->setRotation(90.0f);

	//sprite->setVisible(true);

	//颜色设定                 R     G     B
	//sprite->setColor(Color3B(255, 0, 0));
	//sprite->setColor(Color3B(0, 0, 255));
	//左右镜像
	//sprite->setFlippedX(true);
	//                    画面的右上为基准点(0,0), 显示（100 100）的范围       
	sprite->setTextureRect(Rect(0, 64, 32, 32));
	//不透明度设定
	//sprite->setOpacity(128);

	//添加完图像之后要做添加处理
	this->addChild(sprite);
	//this->addChild(sprite2);

	this->scheduleUpdate();


    return true;

}


void HelloWorld::menuCloseCallback(Ref* pSender)
{

    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
void HelloWorld::update(float delta)
{
	
	//ここに更新処理を書く
	
	//Vec2 pos = sprite->getPosition();

	//
	//if (pos.x <= 0&&pos.y>0)
	//{
	//	pos += Vec2(0.0f, -5.0f);
	//}
	//else if (pos.y <= 0&&pos.x<=1280)
	//{
	//	pos += Vec2( 5.0f, 0.0f);
	//}
	//else if (pos.x>=1280&&pos.y<=720)
	//{
	//	pos += Vec2(0.0f, 5.0f);
	//}
	//else 
	//{
	//	pos += Vec2(-5.0f, 0.0f);
	//}
 //   

	//sprite->setPosition(pos);




	////float a = sprite->getOpacity();
	////a -= 5.1f;
	////sprite->setOpacity(a);

	counter ++;
	//sprite->setOpacity((180 - counter) / 180.0f*250.0f);
	//sprite2->setOpacity(counter/180.0f*255.0f);
    //sprite->setColor(Color3B((180-counter)/180.0f*255.0f, 0, counter/180.0f*255.0f));
    //sprite->setColor(Color3B(0, 0, 255));
	switch (counter/10 % 4)
	{
		case 0:
		sprite->setTextureRect(Rect(0, 64, 32, 32));
		break;
		case 1:
		sprite->setTextureRect(Rect(32, 64, 32, 32));
		break;
		case 2:
		sprite->setTextureRect(Rect(64, 64, 32, 32));
		break;
		case 3:
		sprite->setTextureRect(Rect(32, 64, 32, 32));
		break;
	}

    

}