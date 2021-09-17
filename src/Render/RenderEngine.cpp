#include "RenderEngine.h"

#include <QDebug>

#include "Render/Graph/RenderQueue.h"
#include "Utils/RenderUtils.h"

#include "Render/Base/RenderBuffer.h"
#include "Render/Base/FrameBuffer.h"
#include "Render/Base/Texture.h"


#include "Systems/Primitive/TriangleSystem.h"
#include "Systems/Primitive/QuadSystem.h"

CFEngineRender::RenderEngine::RenderEngine():textureToRender_(nullptr),textureToDisplay_(nullptr),textureToDelete_(nullptr){
  m_systems.push_back(new CFEngineRender::TriangleSystem());
  m_systems.push_back(new CFEngineRender::QuadSystem());
}

CFEngineRender::RenderEngine::~RenderEngine() noexcept {
    for(auto& item: m_systems){
        delete item;
    }

//    // 删除gl资源
//    textureToRender_->release();
//    textureToDisplay_->release();
//    rbo_->release();
//    fbo_->release();
}


void CFEngineRender::RenderEngine::update(float dt){

//    fbo_->bindTexture(textureToRender_);
//
//    fbo_->use();
//
//    if(textureToDelete_ && textureToDelete_->valid()){
//        textureToDelete_->release();
//    }

    auto input = std::make_shared<CFEngineRender::FrameBuffer>(400,600);
    auto output = std::make_shared<CFEngineRender::FrameBuffer>(400,600);

    renderQueue = std::make_shared<CFEngineRender::RenderQueue>();
    renderQueue->setInput(input);
    renderQueue->setOutput(output);
    int i = 1;
    for (System *system : m_systems) {
        renderQueue->addRenderer(system->update(ENTT::registry, dt),std::to_string( i++));
    }
    renderQueue->render();
    // Utils::saveFBOToImage( renderQueue->output()->handle(),QSize(400,600), "D:\\GameEngine\\CFRenderEngine\\" + renderQueue->id() + ".png", QOpenGLContext::currentContext());
//    unsigned int value = textureToDisplay_->handle();
//    textureToDisplay_->setHandle(textureToRender_->handle());
//    textureToRender_->setHandle(value);
//
//    qSwap(m_textureToDisplay, m_textureToRender);

}

void CFEngineRender::RenderEngine::setRenderSize(int width,int height){
    if(m_width == width && m_height == height){
       return;
    }
    m_width = width;
    m_height = height;
//    initializeOpenGLFunctions();

//    // 创建纹理
//    if(textureToRender_ && textureToRender_->valid()){
//        textureToRender_->release();
//    }
//    textureToDisplay_ = std::make_shared<CFEngineRender::Texture>(width,height);
//    textureToRender_ = std::make_shared<CFEngineRender::Texture>(width,height);
//
//    // 创建FBO
//    if(fbo_ && fbo_->valid()){
//        fbo_->release();
//    }
//    fbo_ = std::make_shared<CFEngineRender::FrameBuffer>();
//
//
//    // 创建rbo
//    if(rbo_ && rbo_->valid()){
//        rbo_->release();
//    }
//    rbo_ = std::make_shared<CFEngineRender::RenderBuffer>(width,height);
//
//    fbo_->bindRenderBuffer(rbo_);
//    fbo_->bindTexture(textureToRender_);
//
//    renderer_->setOutput(fbo_);
}