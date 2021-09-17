#pragma once

#include <QColor>

#include <vector>

#include "Components/Base/UIComponent.h"
#include "Components/ComponentManager.h"

CFENGINE_RENDER_START

class Quad: public UIComponent{
Q_OBJECT

    Q_PROPERTY(QString name READ name)
    Q_PROPERTY(QColor color READ color)

public:

    Quad(){
        this->MakeComponentPropertyDescriptions();

        componentDescription_ = ComponentManager::componentDescriptionWithType(CFEngineRender::ComponentType::kQuad);

    }
    Quad(int componentId, int entityId):UIComponent(componentId,entityId){
        this->MakeComponentPropertyDescriptions();

        componentDescription_ = ComponentManager::componentDescriptionWithType(CFEngineRender::ComponentType::kQuad);
    }

    ~Quad() = default;

    static std::shared_ptr<ComponentDescription> MakeComponentDescription(){
        auto quad_ = std::make_shared<CFEngineRender::ComponentDescription>();
        quad_->type_ = ComponentType::kQuad;
        quad_->group_ = ComponentGroup::kPrimitive;
        quad_->label_ = "Quad";
        quad_->isHiddenInList_ = false;

        return quad_;
    }

    void MakeComponentPropertyDescriptions() override{
        //
        ComponentPropertyDescription* name = new ComponentPropertyDescription;
        name->name_ = "name";
        name->label_ = "name";
        name->type_ = ComponentPropertyType::kString;
        name->editable_ = false;

        ComponentPropertyDescription* color = new ComponentPropertyDescription;
        color->name_ = "color";
        color->label_ = "color";
        color->type_ = ComponentPropertyType::kColor;

        ComponentPropertyDescription* enable = new ComponentPropertyDescription;
        enable->name_ = "enable";
        enable->label_ = "enable";
        enable->type_ = ComponentPropertyType::kBool;

        this->propertyDescriptions_.emplace_back(name);
        this->propertyDescriptions_.emplace_back(color);
        this->propertyDescriptions_.emplace_back(enable);
    }


    std::vector<float> vertices = {
            // positions
            0.5f,  0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            -0.5f,  0.5f, 0.0f,
    };

    std::vector<unsigned int> indices = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
    };

public:

    QString name_ = "Quad";
    QString name(){
        return name_;
    }


    QColor color_ = QColor(255, 0, 0, 127);
    QColor color(){
        return color_;
    }

signals:
};
CFENGINE_RENDER_END