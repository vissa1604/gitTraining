team: workshop
pipeline: simple-java-web
tasks:
- type: run
  name: build
  script: build.sh
  save_artifacts:
  - build/libs
  docker:
    image: openjdk:11-jdk-slim
- type: deploy-cf
  name: dev
  api: ((cloudfoundry.api-snpaas))
  space: dev
  manifest: ci/manifest.yml
  deploy_artifact: build/libs/simple-java-web.jar
  vars:
    TOKEN: ((simple-java-web.token))
    API-KEY: ((simple-java-web.api-key))
